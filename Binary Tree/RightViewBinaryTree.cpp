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

vector<int> leftView(Node *root)
{
    vector<int> res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        bool flag = true;
        int size = q.size();
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            if(flag){
                res.push_back(node->data);
                flag = false;
            }

            if(node->right != NULL)
                q.push(node->right);

            if(node->left != NULL)
                q.push(node->left);
        }
    }
    
    return res;
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->right->left = new Node(10);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->right->left->right = new Node(14);
    root->left->right->left->right = new Node(56);

    auto res = leftView(root);
    for(auto it : res)
        cout << it << " ";
}