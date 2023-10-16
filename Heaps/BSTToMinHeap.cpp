#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node *root, int val){
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insertBST(root->left, val);
    
    else if(val > root->data)
        root->right = insertBST(root->right, val);
    
    return root;
}
void traverse(Node* root){
    if(root == NULL)
        return;
    
    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
}
void inorder(Node* root, vector<int> &in){
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
void util(Node* root, vector<int> &in, int &index){
    if(root == NULL)
        return;
    
    root->data = in[index];
    index++;

    util(root->left, in, index);
    util(root->right, in, index);
}
Node* BSTToMinHeap(Node* root){
    vector<int> in;
    int index = 0;
    inorder(root, in);
    util(root, in, index);
    return root;
}
int main(){
    Node *root = NULL;
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 5);
    root = insertBST(root, 7);
    root = insertBST(root, 1);
    
    traverse(root);
    root = BSTToMinHeap(root);
    cout << endl;
    traverse(root);
}