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
void zigzagTraversal(Node* root){
    vector<vector<int>> ans;
    bool flag = true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> vec(size);
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            
            int index = (flag) ? i : (size - i - 1);
            vec[index] = node->data;

            if(node->left != NULL)
                q.push(node->left);

            if(node->right != NULL)
                q.push(node->right);
        }
        flag = !flag;
        ans.push_back(vec);
    }
    for(auto it : ans){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
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
    zigzagTraversal(root);
}