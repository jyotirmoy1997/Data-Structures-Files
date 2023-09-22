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
bool rec(Node* left, Node* right){
    if(left == NULL || right == NULL)
        return left == right;

    if(left->data != right->data)
        return false;
    
    return rec(left->left, right->right) && rec(left->right, right->left);
}
bool isSymmetric(Node* root){
    return root == NULL || rec(root->left, root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << isSymmetric(root);
}