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
void topView(Node *root)
{
    unordered_map<int, int> mp;
    int mx=0, mn=0, hd=0;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, hd));
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        hd = it.second;
        if(mp.find(hd) == mp.end())
        {
            mp[hd] = node->data;
        }
        if(node->left)
            q.push(make_pair(node->left, hd-1));
        if(node->right)
            q.push(make_pair(node->right, hd+1));
        if(mn>hd)
          mn=hd;
        else if(mx<hd)
          mx=hd;
    }
    for(int i=mn; i<=mx; i++)
    {
        cout << mp[i] << " ";
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
    topView(root);
}