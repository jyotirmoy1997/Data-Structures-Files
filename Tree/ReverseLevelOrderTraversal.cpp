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
void reverseLevelOrder(Node *root)
{
    stack<int> st;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        auto node = q.front();
        // cout << node->data << " ";
        q.pop();
        st.push(node->data);
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }
    while(!st.empty())
    {
        auto node = st.top();
        st.pop();
        cout << node << " ";
    }
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
    reverseLevelOrder(root);
}