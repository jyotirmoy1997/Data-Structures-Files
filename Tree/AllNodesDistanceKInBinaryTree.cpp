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
vector<int> distanceK(Node* root, Node* target, int k){
    unordered_map<Node*, Node*> parentMap;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node->left != NULL){
            parentMap[node->left] = node;
            q.push(node->left);
        }
        if(node->right != NULL){
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }

    int distance = 0;
    unordered_map<Node*, int> vis;
    q.push(target);
    vis[target] = 1;
    while(distance < k){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto node = q.front();
            // cout << node->data << " ";
            q.pop();
            if(node->left != NULL && vis[node->left] == 0){
                q.push(node->left);
                vis[node->left] = 1;
            }
            if(node->right != NULL && vis[node->right] == 0){
                q.push(node->right);
                vis[node->right] = 1;
            }
            if(parentMap.find(node) != parentMap.end() && vis[parentMap[node]] == 0){
                q.push(parentMap[node]);
                vis[parentMap[node]] = 1;
            }
        }
        // cout << endl;
        distance++;
    }
    vector<int> res;
    while(!q.empty()){
        // cout << q.front() << " ";
        res.push_back(q.front()->data);
        q.pop();
    }
    return res;
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
    Node *root = new Node(3);
    root->left = new Node(5);

    Node* temp = root->left;
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    // inOrder(root);
    // cout << endl;
    vector<int> res = distanceK(root, temp, 2);


    for(auto it : res)
        cout << it << " ";
}