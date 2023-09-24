#include<iostream>
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
void inorderMorrisTraversal(Node *root)
{
    Node *current = root;
    while(current != NULL)
    {
        if(current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            Node *pred = current->left;
            while(pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }
            if(pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                cout << current->data << " ";
                pred->right = NULL;
                current = current->right;
            }
        }
    }
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

    inorderMorrisTraversal(root);
}