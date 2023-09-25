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
int identicalTrees(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return 1;
    Node *ptr1 = root1;
    Node *ptr2 = root2;
    int id = 0;
    if(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data == ptr2->data)
        {
            if(identicalTrees(ptr1->left, ptr2->left) && identicalTrees(ptr1->right, ptr2->right))
            {
                id = 1;
            }
        }
    }
    return id;
}
int main()
{
    Node *root1 = NULL;
    root1 = insertRoot(root1, 5);
    insertBNTree(root1, 5, 7);
    insertBNTree(root1, 5, 8);
    insertBNTree(root1, 7, 9);
    insertBNTree(root1, 8, 11);
    insertBNTree(root1, 7, 10);

    Node *root2 = NULL;
    root2 = insertRoot(root2, 5);
    insertBNTree(root2, 5, 7);
    insertBNTree(root2, 5, 8);
    insertBNTree(root2, 7, 9);
    insertBNTree(root2, 8, 11);
    insertBNTree(root2, 7, 10);

    cout << identicalTrees(root1, root2);
}