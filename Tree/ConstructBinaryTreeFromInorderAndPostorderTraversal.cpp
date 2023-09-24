#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* constructTree(vector<int> &postorder, int postStart, int postEnd, 
                            vector<int> &inorder, int inStart, int inEnd, 
                            unordered_map<int, int> &inMap){
    if(postStart > postEnd || inStart > inEnd) 
        return NULL;

    Node* root = new Node(postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root -> left = constructTree(postorder, postStart, postStart + numsLeft - 1, 
                                 inorder, inStart, inRoot - 1, inMap);
    root -> right = constructTree(postorder, postStart + numsLeft, postEnd - 1, 
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}
Node* buildTree(vector<int> &postorder, vector<int> &inorder){
    unordered_map<int, int> inMap;
    for (int i = 0; i <inorder.size(); i++)
        inMap[inorder[i]] = i;

    return constructTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
}
void inOrder(Node* root){
    if(root == NULL)
        return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Node* root = buildTree(postorder, inorder);
    inOrder(root);
}