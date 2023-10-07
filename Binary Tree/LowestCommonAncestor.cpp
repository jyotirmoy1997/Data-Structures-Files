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
Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root == NULL || root == p || root == q)
        return root;
    
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL)
        return right;

    else if(right == NULL)
        return left;

    else
        return root;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);

    Node* p = root->left;
    Node* q = root->left->right->left;

    auto node = lowestCommonAncestor(root, p, q);
    cout << node->data;
    
}