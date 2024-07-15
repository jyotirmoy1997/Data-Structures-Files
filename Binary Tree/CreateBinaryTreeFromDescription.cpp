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
void inOrder(TreeNode* root){
    if(root == NULL)
        return;
    
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> mp;
    unordered_set<int> hasParent;
    for(int i = 0; i < descriptions.size(); i++) {
        if(mp.find(descriptions[i][0]) == mp.end())
            mp[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
        if(mp.find(descriptions[i][1]) == mp.end())
            mp[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
        hasParent.insert(descriptions[i][1]);
    }
    
    TreeNode* root;
    for(int i = 0; i < descriptions.size(); i++) {
        if(descriptions[i][2]) { //left
            mp[descriptions[i][0]] -> left = mp[descriptions[i][1]];
        } else { //right
            mp[descriptions[i][0]] -> right = mp[descriptions[i][1]];
        }
        if(hasParent.find(descriptions[i][0]) == hasParent.end()) {
            root = mp[descriptions[i][0]];
        }
    }
    return root;
}
int main(){
   vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
   TreeNode* root = createBinaryTree(descriptions);
   inOrder(root);

}