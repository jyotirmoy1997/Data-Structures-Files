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
void verticalOrder(Node *root)
{
    unordered_map<int, vector<int>> mp;
    int mx=0, mn=0, hd=0;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, hd));
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        hd = it.second;
        mp[hd].push_back(node->data);
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
        vector<int> tmp = mp[i];
        for(int j=0;j<tmp.size();j++)
          cout<<tmp[j]<<" ";
        cout<<endl;
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
    verticalOrder(root);
}