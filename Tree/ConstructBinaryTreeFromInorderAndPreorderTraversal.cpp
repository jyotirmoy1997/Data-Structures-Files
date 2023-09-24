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
Node* constructTree(vector<int> &preorder, int preStart, int preEnd, 
                            vector<int> &inorder, int inStart, int inEnd, 
                            unordered_map<int, int> &inMap){
    if(preStart > preEnd || inStart > inEnd) 
        return NULL;

    Node* root = new Node(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root -> left = constructTree(preorder, preStart + 1, preStart + numsLeft, 
                                 inorder, inStart, inRoot - 1, inMap);
    root -> right = constructTree(preorder, preStart + numsLeft + 1, preEnd, 
                                  inorder, inRoot + 1, inEnd, inMap);

    return root;
}
Node* buildTree(vector<int> &preorder, vector<int> &inorder){
    unordered_map<int, int> inMap;
    for (int i = 0; i <inorder.size(); i++)
        inMap[inorder[i]] = i;

    return constructTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
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
    vector<int> preorder = {3,9,20,15,7};
    Node* root = buildTree(preorder, inorder);
    inOrder(root);
}