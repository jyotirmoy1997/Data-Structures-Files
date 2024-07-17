#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
TreeNode* dfs(TreeNode* root, unordered_set<int> &st, unordered_set<TreeNode*> &res){
    if(root == NULL)
        return NULL;
    
    TreeNode* node = root;
    if(st.find(root->val) != st.end()){
        node = NULL;
        if(res.find(root) != res.end())
            res.erase(root);
        
        if(root->left != NULL)
            res.insert(root->left);

        if(root->right != NULL)
            res.insert(root->right);
    }
    root->left = dfs(root->left, st, res);
    root->right = dfs(root->right, st, res);

    return node;
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    unordered_set<int> st(to_delete.begin(), to_delete.end());
    unordered_set<TreeNode*> res;
    TreeNode* node = dfs(root, st, res);
    vector<TreeNode*> forest(res.begin(), res.end());
    return forest;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> to_delete = {3, 5};
    delNodes(root, to_delete);
}