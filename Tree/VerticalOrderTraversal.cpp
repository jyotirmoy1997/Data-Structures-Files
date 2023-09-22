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

// This traversal does not take the level of the tree into account.
// It is important to note that Only the node values at the same level have to be sorted
vector<vector<int>> verticalOrder(Node *root)
{
    unordered_map<int, vector<int>> mp;
    int mx=0, mn=0, hd=0;
    queue<pair<Node*, int>> q;
    vector<vector<int>> res;
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
        auto tmp = mp[i];
        vector<int> vec(tmp.begin(), tmp.end());
        res.push_back(vec);
    }

    return res;
}

vector<vector<int>> verticalOrderLevelSorted(Node *root)
{
    vector<vector<int>> res;
    map<int, map<int, multiset<int>>> mpp;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        auto node = it.first;
        auto level = it.second.first;
        auto vertical = it.second.second;

        mpp[vertical][level].insert(node->data);
        if(node->left != NULL)
            q.push({node->left, {level + 1, vertical - 1}});

        if(node->right != NULL)
            q.push({node->right, {level + 1, vertical + 1}});
    }
    for(auto it : mpp){
        vector<int> vec;
        for(auto el : it.second){
            vec.insert(vec.end(), el.second.begin(), el.second.end());
        }
        res.push_back(vec);
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
    auto res = verticalOrder(root);

    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}