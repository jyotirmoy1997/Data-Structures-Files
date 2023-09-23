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
Node* reorder(Node* root){
    int sum = 0;
    if(root->left != NULL)
        sum += root->left->data;

    if(root->right != NULL)
        sum += root->right->data;

    if(sum < root->data){
        if(root->left != NULL)
            root->left->data = root->data;

        if(root->right != NULL)
            root->right->data = root->data;
    }
    return root;
}
Node* childrenSum(Node* root){
    if(root == NULL)
        return NULL;

    
    root = reorder(root);
    Node* left = childrenSum(root->left);
    Node* right = childrenSum(root->right);

    
    if(left == NULL && right == NULL)
        return root;

    int total = 0;
    if(left != NULL)
        total += left->data;
    
    if(right != NULL)
        total += right->data;

    root->data = total;
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
    Node *root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    inOrder(root);
    root = childrenSum(root);
    cout << endl;
    inOrder(root);
}