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
Node* search(Node *root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == val)
    {
        // cout << "Reach";
        return root;
    }
    else
    {
        Node *temp = search(root->left, val);
        if(temp == NULL)
        {
            temp = search(root->right, val);
        }
        return temp;
    }
}
Node* insertRoot(Node *root, int val)
{
    return new Node(val);
}
Node* insertBNTree(Node *root, int key, int val)
{

    Node *temp = search(root, key);
    if(temp->left == NULL)
    {
        temp->left = new Node(val);
    }
    else if(temp->right == NULL)
    {
        temp->right = new Node(val);
    }
    else
    {
        cout << "Insertion Not Possible at Desired Node";    
    }
    return root;
}
void inorder(Node *root, vector<int> &vec)
{
    Node *temp = root;
    if(root == NULL)
    {
        return;
    }
    inorder(temp->left, vec);
    vec.push_back(root->data);
    inorder(temp->right, vec);
}
void inorderBST(Node *root, vector<int> &vec, int &i)
{
    Node *temp = root;
    if(root == NULL)
    {
        return;
    }
    inorderBST(temp->left, vec, i);
    root->data = vec[i];
    i++;
    inorderBST(temp->right, vec, i);
}
void traverseInorder(Node *root)
{
    Node *temp = root;
    if(root == NULL)
    {
        return;
    }
    traverseInorder(temp->left);
    cout << root->data << " ";
    traverseInorder(temp->right);
}
Node* convertToBST(Node *root)
{
    vector<int> vec;
    inorder(root, vec);
    sort(vec.begin(), vec.end());
    int i=0;
    inorderBST(root, vec, i);
    return root;
}
void inorderTraversal(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main()
{
    Node *root = NULL;
    root = insertRoot(root, 1);
    insertBNTree(root, 1, 2);
    insertBNTree(root, 1, 3);
    insertBNTree(root, 2, 4);
    // insertBNTree(root, 8, 11);
    // insertBNTree(root, 7, 10);
    // traverseInorder(root);
    root = convertToBST(root);
    traverseInorder(root);
}