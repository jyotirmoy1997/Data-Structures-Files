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
bool findTarget(Node* root, int k){
    stack<Node*> st1;
    stack<Node*> st2;

    Node* curr1 = root;
    Node* curr2 = root;

    while(curr1 != NULL){
        st1.push(curr1);
        curr1 = curr1->left;
    }
    while(curr2 != NULL){
        st2.push(curr2);
        curr2 = curr2->right;
    }
    bool res = false;
    while(!st1.empty() && !st2.empty()){
        auto n1 = st1.top();
        auto n2 = st2.top();

        if(n1 != n2 && (n1->data + n2->data == k)){
            res = true;
            break;
        }
        else if(n1 != n2 && (n1->data + n2->data < k)){
            st1.pop();
            n1 = n1->right;
            while(n1 != NULL){
                st1.push(n1);
                n1 = n1->left;
            }
        } 
        else if(n1 != n2 && (n1->data + n2->data > k)){
            st2.pop();
            n2 = n2->left;
            while(n2 != NULL){
                st2.push(n2);
                n2 = n2->right;
            }
        }    
    }
    return res;
} 
int main(){
    Node *root = NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 7);
    
    cout << findTarget(root, 9);
    

}