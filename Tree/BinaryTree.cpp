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
void traverseInorder(Node *root)
{
    Node *temp = root;
    if(root == NULL)
    {
        return;
    }
    traverseInorder(temp->left);
    cout << temp->data << " ";
    traverseInorder(temp->right);
}
int main()
{
    Node *root = NULL;
    root = insertRoot(root, 5);
    insertBNTree(root, 5, 7);
    insertBNTree(root, 5, 8);
    insertBNTree(root, 7, 9);
    insertBNTree(root, 8, 11);
    insertBNTree(root, 7, 10);
    traverseInorder(root);
}