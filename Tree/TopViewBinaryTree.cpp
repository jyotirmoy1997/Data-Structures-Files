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

vector<int> topView(Node *root)
{
    vector<int> res;
    queue<pair<Node*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        auto node = it.first;
        auto vertical = it.second;
        if(mp.find(vertical) == mp.end())
            mp[vertical] = node->data;
            
        if(node->left != NULL)
            q.push({node->left, vertical - 1});

        if(node->right != NULL)
            q.push({node->right, vertical + 1});
    }
    for(auto it : mp){
        res.push_back(it.second);
    }
    return res;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    auto res = topView(root);
    for(auto it : res)
        cout << it << " ";
}