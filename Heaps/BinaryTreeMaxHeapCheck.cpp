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
bool checkTree(Node* root, int index, int totalNodes){
    if(root == NULL)
        return true;

    if(index >= totalNodes)
        return false;

    bool left = checkTree(root->left, 2 * index + 1, totalNodes);
    bool right = checkTree(root->right, 2 * index + 2, totalNodes);

    return left && right;
}
int countNodes(Node* root){
    if(root == NULL)
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isMaxOrder(Node* root){
    if(root == NULL)
        return true;

    bool left = true, right = true;
    if(root->left != NULL)
        left = root->data > root->left->data;
    
    if(root->right != NULL)
        right = root->data > root->right->data;

    return left && right;
}
bool checkMaxHeap(Node* root){
    int nodes = countNodes(root);
    return checkTree(root, 0, nodes) && isMaxOrder(root);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(6);
    // root->right->right = new Node(5);

    cout << checkMaxHeap(root);
}