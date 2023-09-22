#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isLeaf(Node* node){
    if(node->left == NULL && node->right == NULL)
        return true;
    
    return false;
}
void addLeft(Node* root, vector<int> &res){
    Node* curr = root->left;
    while(curr != NULL){
        if(!isLeaf(curr))
            res.push_back(curr->data);
        
        if(curr->left != NULL)
            curr = curr->left;
        
        else
            curr = curr->right;
    }
}
void addRight(Node* root, vector<int> &res){
    Node* curr = root->right;
    stack<int> st;
    while(curr != NULL){
        if(!isLeaf(curr))
            st.push(curr->data);
        
        if(curr->right != NULL)
            curr = curr->right;
        
        else
            curr = curr->left;
    }
    while(!st.empty()){
        // cout << st.top() << " ";
        res.push_back(st.top());
        st.pop();
    }

}
void addLeaves(Node* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
        
    
    if(root->left != NULL)
        addLeaves(root->left, res);

    if(root->right != NULL)
        addLeaves(root->right, res);
}
vector<int> boundaryTraversalAntiClockwise(Node* root){
    vector<int> res;

    res.push_back(root->data);
    addLeft(root, res);
    addLeaves(root, res);
    addRight(root, res);


    return res;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);
    
    auto res = boundaryTraversalAntiClockwise(root);
    for(auto it : res)
        cout << it << " ";
}