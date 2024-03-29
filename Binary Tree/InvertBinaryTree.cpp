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
Node* invertBinaryTree(Node* root){
    if(root == NULL)
        return NULL;

    Node* left = invertBinaryTree(root->left);
    Node* right = invertBinaryTree(root->right);

    root->left = right;
    root->right = left;

    return root;
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
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    inOrder(root);
    root = invertBinaryTree(root);
    cout << endl;
    inOrder(root);
}