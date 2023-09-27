/* Approach =>

    1. First Convert Two BSTs into Two Sorted DLLs.
    2. Merge these two Sorted DLLs.
    3. Convert the Final Merged Sorted DLL into a BST.


*/

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
Node* mergeSortedDLL(Node* h1, Node* h2){
    Node* d = new Node(0);
    if(h1->data > h2->data)
        d->right = h2;

    else
        d->right = h1;

    Node* p1 = h1;
    Node* p2 = h2;
    Node* curr = d;
    while(p1 != NULL && p2 != NULL){
        if(p1->data > p2->data){
            curr->right = p2;
            p2->left = curr;
            p2 = p2->right;
        }
        else{
            curr->right = p1;
            p1->left = curr;
            p1 = p1->right;
        }
        curr = curr->right;
    }
    if(p1 == NULL){
        curr->right = p2;
        p2->left = curr;
    }
        
    else if(p2 == NULL){
        curr->right = p1;
        p1->left = curr;
    }
        
    Node* head = d->right;
    d->right = NULL;
    head->left = NULL;
    return head;
}
int countNodes(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->right;
    }
    return count;
}
Node* sortedLLToBST(Node* &head, int n){
    if(n <= 0 || head == NULL)
        return NULL;

    Node* left = sortedLLToBST(head, n/2);
    Node* root = head;
    root->left = left;

    head = head->right;
    root->right = sortedLLToBST(head, n - n/2 - 1);

    return root;
}
Node* mergeTwoBST(Node* root1, Node* root2){

    // Convert 2 BST into 2 Sorted DLLs
    Node* head1 = NULL;
    Node* prev1 = NULL;
    convertBSTToDLL(root1, prev1, head1);

    Node* head2 = NULL;
    Node* prev2 = NULL;
    convertBSTToDLL(root2, prev2, head2);

    Node* h3 = mergeSortedDLL(head1, head2);
    int n = countNodes(h3);

    return sortedLLToBST(h3, n);
}
void traverseInorder(Node* root){
    if(root == NULL)
        return;

    traverseInorder(root->left);
    cout << root->data << " ";
    traverseInorder(root->right);
}
int main(){
    Node *root1 = NULL;
    root1 = insertBST(root1, 10);
    root1 = insertBST(root1, 8);
    root1 = insertBST(root1, 12);
    root1 = insertBST(root1, 16);
    root1 = insertBST(root1, 20);
    root1 = insertBST(root1, 4);
    root1 = insertBST(root1, 2);

    Node *root2 = NULL;
    root2 = insertBST(root2, 17);
    root2 = insertBST(root2, 14);
    root2 = insertBST(root2, 11);
    root2 = insertBST(root2, 15);
    root2 = insertBST(root2, 22);
    root2 = insertBST(root2, 21);
    
    Node* root3 = mergeTwoBST(root1, root2);
    traverseInorder(root3);
}