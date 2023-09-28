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
int minDepth(Node* root){
    int mini = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            if(node->left == NULL && node->right == NULL)
                return mini;

            if(node->left != NULL)
                q.push(node->left);

            if(node->right != NULL)
                q.push(node->right);
        }
        mini++;
    }
    return mini;
}
void inOrder(Node* root){
    if(root == NULL)
        return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(60);
    root->left->left->left = new Node(90);
    root->left->left->right = new Node(55);
    root->right->left = new Node(40);
    
    cout << minDepth(root);

}