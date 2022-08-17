#include<iostream>
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
Node* insertBST(Node *root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }
    if(val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}
Node* searchBST(Node *root, int val)
{
    Node *temp = NULL;
    if(root->data == val)
    {
        return root;
    }
    else if(root->data > val)
    {
        temp = searchBST(root->left, val);
    }
    else if(root->data < val)
    {
        temp = searchBST(root->right, val);
    }
    return temp;
}
Node* inorderSuccesorDel(Node *root)
{
    Node *current = root;
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
Node* inorderPredecessor(Node *root)
{
    Node *current = root;
    while(current && current->right != NULL)
    {
        current = current->right;
    }
    return current;
}
Node* deleteBST(Node *root, int val)
{
    if(val < root->data)
    {
        root->left = deleteBST(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = deleteBST(root->right, val);
    }
    else
    {
        if(root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSuccesorDel(root->right);
        root->data = temp->data;
        free(temp);
    }
    return root;
}
Node* flattenBinaryTree(Node *root)
{
    Node* current = root;
    while(current != NULL)
    {
        if(current->left != NULL)
        {
            Node *pred = current->left;
            while(pred->right != NULL)
            {
                pred = pred->right;
            }
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
    return root;
}
void traverse(Node *header)
{
    Node *ptr = header;
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->right;
    }
}
int main()
{
    Node *root = NULL;
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 5);
    root = insertBST(root, 7);
    root = insertBST(root, 1);
    Node *header = flattenBinaryTree(root);
    traverse(header);
    // inorderMorrisTraversal(root);
}