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

// Finding Ceil of a Val means finding the Inorder Successor of a key even if 
// the key doesn't exist in the BST
int floor(Node* root, int key){
    Node* temp = root;
    int floorVal = INT_MAX;
    while(temp != NULL){
        if(temp->data > key)
            temp = temp->left;
        else{
            floorVal = (temp->data != key) ? temp->data : floorVal;
            temp = temp->right;
        }
            
    }
    return floorVal;
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
    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 13);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 9); 
    root = insertBST(root, 11); 
    root = insertBST(root, 14);
    
    inorderTraversal(root);
    cout << endl << floor(root, 9);
}