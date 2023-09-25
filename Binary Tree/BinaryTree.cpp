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
        return NULL;

    if(root->data == val)
        return root;

    else{
        Node *temp = search(root->left, val);
        if(temp == NULL)
            temp = search(root->right, val);

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

    if (temp == NULL)
    {
        cout << "Key " << key << " not found in the tree. Insertion Not Possible." << endl;
        return root;
    }

    if (temp->left == NULL)
        temp->left = new Node(val);
    else if (temp->right == NULL)
        temp->right = new Node(val);
    else
        cout << "Insertion Not Possible at Desired Node" << endl;

    return root;
}

void inorderTraversal(Node *root)
{
    Node *temp = root;
    if(root == NULL)
        return;

    inorderTraversal(temp->left);
    cout << temp->data << " ";
    inorderTraversal(temp->right);
}
void preorderTraversal(Node *root)
{
    Node *temp = root;
    if(root == NULL)
        return;

    cout << temp->data << " ";
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
}
void postorderTraversal(Node *root)
{
    Node *temp = root;
    if(root == NULL)
        return;

    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout << temp->data << " ";
}
int main()
{
    Node *root = NULL;
    root = insertRoot(root, 1);
    root = insertBNTree(root, 1, 2);
    root = insertBNTree(root, 1, 3);
    root = insertBNTree(root, 2, 4);
    root = insertBNTree(root, 8, 11);
    root = insertBNTree(root, 7, 10);
    inorderTraversal(root);
    cout << endl;
    preorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    return 0;
}