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
void inorderRec(Node* root, Node* &prev, Node* &first, Node* &middle, Node* &last){
    if(root == NULL)
        return;
    
    inorderRec(root->left, prev, first, middle, last);
    if(prev != NULL && prev->data > root->data){
        if(first == NULL){
            first = prev;
            middle = root;
        }
        else
            last = root;
    }
    prev = root;
    inorderRec(root->right, prev, first, middle, last);
}
Node* recoverTree(Node* root){
    Node* first = NULL;
    Node* middle = NULL;
    Node* last = NULL;
    Node* prev = NULL;
    inorderRec(root, prev, first, middle, last);

    if(last == NULL)
        swap(middle->data, first->data);
    else
        swap(last->data, first->data); 
    
    return root;
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
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 5);
    root = insertBST(root, 7);
    root = insertBST(root, 1);
    
    swap(root->right->data, root->left->right->data);
    
    inorderTraversal(root);
    root = recoverTree(root);
    cout << endl;
    inorderTraversal(root);
}