#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node *root, int val){
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insertBST(root->left, val);
    
    else if(val > root->data)
        root->right = insertBST(root->right, val);
    
    return root;
}
void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
        cout << node->data << " ";
    }
}
void inorder(Node* root, vector<int> &in){
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
Node* buildTree(int low, int high, vector<int> &in){
    if(low > high)
        return NULL;
    
    int mid = (low + high)/2;

    Node* root = new Node(in[mid]);
    root->left = buildTree(low, mid-1, in);
    root->right = buildTree(mid+1, high, in);

    return root;
}
Node* balancedBST(Node* root){
    vector<int> in;
    inorder(root, in);
    return buildTree(0, in.size()-1, in);
}
int main(){
    Node *root = NULL;
    root = insertBST(root, 10);
    root = insertBST(root, 8);
    root = insertBST(root, 12);
    root = insertBST(root, 16);
    root = insertBST(root, 20);
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    

    levelOrderTraversal(root);
    cout << endl;
    root = balancedBST(root);
    levelOrderTraversal(root);
}