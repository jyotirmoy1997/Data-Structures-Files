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
Node* flattenBinaryTree(Node *root)
{
    Node* current = root;
    while(current != NULL)
    {
        if(current->left != NULL)
        {
            Node *pred = current->left;
            while(pred->right != NULL)
            {
                pred = pred->right;
            }
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    inOrder(root);
    root = flattenBinaryTree(root);
    cout << endl;
    inOrder(root);
}
