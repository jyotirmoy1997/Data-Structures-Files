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
// void getPath(Node* root, vector<vector<int>> &res, vector<int> &vec){
//     vec.push_back(root->data);
//     if(isLeaf(root)){
//         res.push_back(vec);
//     }
//     if(root->left != NULL)
//         getPath(root->left, res, vec);
    
//     if(root->right != NULL)
//         getPath(root->right, res, vec);
    
//     vec.pop_back();
//     return;
// }
// vector<vector<int>> pathToNode(Node* root){
//     vector<vector<int>> res; 
//     vector<int> vec;
//     getPath(root, res, vec);
//     return res;
// }

void getPath(Node* root, string s, vector<string> &res){
    if(isLeaf(root)){
        s += to_string(root->data);
        res.push_back(s);
        return;
    }

    s += to_string(root->data) + "->";

    if(root->left != NULL)
        getPath(root->left, s, res);
    
    if(root->right != NULL)
        getPath(root->right, s, res);

    return;
}
vector<string> pathToNode(Node* root){
    vector<string> res; 
    string s = "";
    getPath(root, s, res);
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
    root->left->right->right = new Node(7);
    
    auto res = pathToNode(root);
    for(auto it : res){
        cout << it << endl;
    }
    // auto res = pathToNode(root);
    // for(auto it : res){
    //     string s = "";
    //     for(auto el : it)
    //         cout << el << " ";
    //     cout << endl;
    // }
}