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
Node* inorderSuccesorDel(Node *root){
    Node *current = root;
    while(current && current->left != NULL)
        current = current->left;
    
    return current;
}
Node* deleteBST(Node *root, int val){
    if(val < root->data)
        root->left = deleteBST(root->left, val);
    
    else if(val > root->data)
        root->right = deleteBST(root->right, val);
    
    else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSuccesorDel(root->right);
        root->data = temp->data;
        free(temp);
    }
    return root;
}
void inorderTraversal(Node *root){
    if(root == NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
Node* inorderPredecessor(Node *root, Node *p){
    Node* succesor = NULL;
    while(root != NULL){
        if(p->data <= root->data)
            root = root->left;
        
        else{
            succesor = root;
            root = root->right;
        }
    }
    return succesor;
}
Node* inorderSuccesor(Node *root, Node *p){
    Node* succesor = NULL;
    while(root != NULL){
        if(p->data >= root->data)
            root = root->right;
        
        else{
            succesor = root;
            root = root->left;
        }
    }
    return succesor;
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
    // inorderTraversal(root);
    // deleteBST(root, 6);
    // cout << endl;
    inorderTraversal(root);
    Node *temp = searchBST(root, 6);
    Node *temp2 = inorderSuccesor(root, temp);
    Node *temp3 = inorderPredecessor(root, temp);
    cout << endl << temp2->data << " " << temp3->data;
}