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
bool getPath(Node* root, int val, vector<int> &vec){
    if(root == NULL)
        return false;

    vec.push_back(root->data);

    if(root->data == val)
        return true;

    if(getPath(root->left, val, vec) || getPath(root->right, val, vec))
        return true;
    
    vec.pop_back();
    return false;
}
vector<int> pathToNode(Node* root, int value){
    vector<int> ans;
    if(root == NULL)
        return ans;

    getPath(root, value, ans);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    
    auto res = pathToNode(root, 7);

    for(auto it : res)
        cout << it << " ";
}