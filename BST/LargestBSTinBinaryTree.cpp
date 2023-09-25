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
struct NodeVal
{
    int maxNode, minNode, maxSize;
    NodeVal(int min, int max, int size)
    {
        maxNode = max;
        minNode = min;
        maxSize = size;
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
NodeVal largestBSTSubtree(Node *root)
{
    if(root == NULL)
    {
        return NodeVal(INT_MAX, INT_MIN, 0);
    }
    auto left = largestBSTSubtree(root->left);
    auto right = largestBSTSubtree(root->right);

    if(left.maxNode < root->data && root->data < right.minNode)
    {
        // It is a BST then
        return NodeVal(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }
    return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(Node *root)
{
    return largestBSTSubtree(root).maxSize;
}
int main()
{
    Node *root = NULL;
    root = insertRoot(root, 20);
    insertBNTree(root, 20, 15);
    insertBNTree(root, 20, 40);
    insertBNTree(root, 15, 14);
    insertBNTree(root, 15, 18);
    insertBNTree(root, 18, 16);
    insertBNTree(root, 18, 19);
    insertBNTree(root, 40, 30);
    insertBNTree(root, 40, 60);
    insertBNTree(root, 60, 50);
    Node *ptr = search(root, 14);
    ptr->right = new Node(17);
    cout << largestBST(root);
}