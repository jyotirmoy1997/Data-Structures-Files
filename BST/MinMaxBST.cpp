#include<iostream>
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
Node* searchBST(Node *root, int val){
    Node *temp = NULL;
    if(root->data == val)
        return root;
    
    else if(root->data > val)
        temp = searchBST(root->left, val);
    
    else if(root->data < val)
        temp = searchBST(root->right, val);
    
    return temp;
}
pair<Node*, Node*> minMaxBST(Node* root){
    Node* mini = root;
    Node* maxi = root;
    while(mini->left != NULL)
        mini = mini->left;
    
    while(maxi->right != NULL)
        maxi = maxi->right;
    
    return {mini, maxi};
}
int main(){
    Node *root = NULL;
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 5);
    root = insertBST(root, 7);
    root = insertBST(root, 1);
    
    auto it = minMaxBST(root);
    cout << it.first->data << "-" << it.second->data;
}