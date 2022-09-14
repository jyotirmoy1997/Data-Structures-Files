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
void inorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void recursion(Node *root, int level, vector<int> &res)
{
    if(root == NULL)
        return;
    if(res.size() == level)
        res.push_back(root->data);
    recursion(root->left, level+1, res);
    recursion(root->right, level+1, res);
}
vector<int> leftView(Node *root)
{
    vector<int> res;
    if(root != NULL)
        recursion(root, 0, res);
    return res;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);
    //inorder(root);
    vector<int> res = leftView(root);
    for(auto it : res)
    {
        cout << it << " ";
    }
}