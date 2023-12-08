/* Solution => https://leetcode.com/problems/construct-string-from-binary-tree/solutions/2542357/c-recursive-pre-order-traversal-approach/?envType=daily-question&envId=2023-12-08*/

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
string tree2str(Node* root) {
    string ans = to_string(root->data);
    if (root->left)
        ans += "(" + tree2str(root->left) + ")";

    if (root->right){
        if (!root->left)
            ans += "()";

        ans += "(" + tree2str(root->right) + ")"; 
    }
    return ans;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << tree2str(root);
}