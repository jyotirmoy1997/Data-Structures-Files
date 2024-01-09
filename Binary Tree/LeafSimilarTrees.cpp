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
void findLeaves(Node* root, vector<int> &leaves){
    if(root->left == NULL && root->right == NULL){
        leaves.push_back(root->data);
        return;
    }
    
    findLeaves(root->left, leaves);
    findLeaves(root->right, leaves);
}
bool leafSimilar(Node* root1, Node* root2) {
    vector<int> tree1Leaves;
    vector<int> tree2Leaves;

    findLeaves(root1, tree1Leaves);
    findLeaves(root2, tree2Leaves);


    int i=0, j=0, l1 = tree1Leaves.size(), l2 = tree2Leaves.size();
    while(i < l1 && j < l2){
        if(tree1Leaves[i] != tree2Leaves[j])
            return false;
        
        i++;
        j++;
    }
    return (l1 != l2) ? false : true;
}
int main(){
    Node *root1 = new Node(3);
    root1->left = new Node(5);
    root1->right = new Node(1);
    root1->left->left = new Node(6);
    root1->left->right = new Node(7);
    root1->right->left = new Node(4);
    root1->right->right = new Node(2);
    root1->right->right->left = new Node(9);
    root1->right->right->right = new Node(11);
    root1->right->right->right->left = new Node(8);
    root1->right->right->right->right = new Node(10);

    Node *root2 = new Node(3);
    root2->left = new Node(5);
    root2->right = new Node(1);
    root2->left->left = new Node(6);
    root2->left->right = new Node(2);
    root2->right->left = new Node(9);
    root2->right->right = new Node(8);
    root2->left->right->left = new Node(7);
    root2->left->right->right = new Node(4);

    cout << leafSimilar(root1, root2);
}