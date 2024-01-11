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
pair<int, int> func(Node* root, int &globalMax){
    if(root == NULL)
        return {1e9, -1e9};

    if(root->left == NULL && root->right == NULL)
        return {root->data, root->data};

    // Left Call
    auto minmaxPairLeft = func(root->left, globalMax);

    // Right Call
    auto minmaxPairRight = func(root->right, globalMax);

    int mini = min(minmaxPairLeft.first, minmaxPairRight.first);
    int maxi = max(minmaxPairLeft.second, minmaxPairRight.second);

    globalMax = max(globalMax, max(abs(root->data - mini), abs(root->data - maxi)));

    return {min(mini, root->data), max(maxi, root->data)};
}
int maxAncestorDiff(Node* root) {
    int globalMax = 0;
    auto res = func(root, globalMax);
    return globalMax;
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
}