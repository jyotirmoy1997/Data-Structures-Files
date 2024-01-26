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
void func(Node* root, vector<int> &freq, int &count){
    if(root == NULL)
        return;

    freq[root->data]++;
    func(root->left, freq, count);
    func(root->right, freq, count);

    if(root->left == NULL && root->right == NULL){
        int flag = 0;
        for(int i=1; i<=9; i++){
            if(freq[i] % 2 != 0)
                flag++;
        }
        if(flag <= 1)
            count++;
    }
    freq[root->data]--;
}
int pseudoPalindromicPaths(Node* root){
    int count = 0;
    vector<int> freq(10, 0);
    func(root, freq, count);
    return count;
}
int main(){

}