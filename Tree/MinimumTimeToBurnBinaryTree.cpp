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
int minTimeToBurn(Node* root, Node* target){
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
    
    while(!q.empty()){
        int size = q.size();
        bool flag = false;
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            if(node->left != NULL && vis[node->left] == 0){
                flag = true;
                q.push(node->left);
                vis[node->left] = 1;
            }
            if(node->right != NULL && vis[node->right] == 0){
                flag = true;
                q.push(node->right);
                vis[node->right] = 1;
            }
            if(parentMap.find(node) != parentMap.end() && vis[parentMap[node]] == 0){
                flag = true;
                q.push(parentMap[node]);
                vis[parentMap[node]] = 1;
            }
        }
        if(flag)
            distance++;
    }
    return distance;
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

    Node* temp = root->left;
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << minTimeToBurn(root, temp);
}