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
int maximumWidth(Node* root){
    if(root == NULL)
        return 0;
    
    int ans = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int first, last;
        int mini = q.front().second;
        for(int i=0; i<size; i++){
            int curr = q.front().second - mini;
            auto node = q.front().first;
            q.pop();

            if(i == 0)
                first = curr;
            if(i == size-1)
                last = curr;

            if(node->left != NULL)
                q.push({node->left, curr * 2 + 1});

            if(node->right != NULL)
                q.push({node->right, curr * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
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
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    inOrder(root);
    cout << endl << "Max Width :: " << maximumWidth(root);
}