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

/* Recursively convert the BST to a DLL where left points to prev node sand right points to next node*/
void convertBSTToDLL(Node* root, Node* &prev, Node* &head){
    if(root == NULL)
        return;

    convertBSTToDLL(root->left, prev, head);
    if(prev == NULL)
        head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convertBSTToDLL(root->right, prev, head);
}
void inorder(Node* root, vector<int> &in){
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
void traverseDLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->right; 
    }
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
    
    Node* head = NULL;
    Node* prev = NULL;

    convertBSTToDLL(root, prev, head);
    traverseDLL(head);
}