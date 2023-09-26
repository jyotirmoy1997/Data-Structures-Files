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
Node* inorderPredecessor(Node* root, int val){
    Node* curr = root;
    Node* temp = NULL;
    while(curr != NULL){
        if(curr->data < val){
            temp = curr;
            curr = curr->right;
        }
        else    
            curr = curr->left;
    }
    return temp;
}
void inorderTraversal(Node *root){
    if(root == NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main(){
    Node *root = NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 1);
    root = insertBST(root, 6);
    root = insertBST(root, 9);
    root = insertBST(root, 8);
    root = insertBST(root, 10);
    
    auto node = inorderPredecessor(root, 7);
    cout << node->data;
}