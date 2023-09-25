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
int lheight(Node* root){
    int count = 0;
    while(root){
        count++;
        root = root->left;
    }
    return count;
}
int rheight(Node* root){
    int count = 0;
    while(root){
        count++;
        root = root->right;
    }
    return count;
}
int countNodes(Node* root){
    if(root == NULL)
        return 0;

    int lh = lheight(root);
    int rh = rheight(root);

    if(lh == rh)
        return (int)(pow(2, lh) - 1);

    return 1 + countNodes(root->left) + countNodes(root->right);
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
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Nodes :: " << countNodes(root);
}