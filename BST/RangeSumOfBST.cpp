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
void inorderTraversal(Node *root){
    if(root == NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int rangeSumBST(Node* root, int low, int high) {
    if(root == NULL)
        return 0;

    int sum = 0;
    if(root->data >= low && root->data <= high){
        sum += root->data;
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
    }
    else if(root->data < low)
        sum += rangeSumBST(root->right, low, high);
    
    else if(root->data > high)
        sum += rangeSumBST(root->left, low, high);

    return sum;
}
int main(){
    Node *root = NULL;
    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 18);
    
    // inorderTraversal(root);
    cout << rangeSumBST(root, 7, 15);
}