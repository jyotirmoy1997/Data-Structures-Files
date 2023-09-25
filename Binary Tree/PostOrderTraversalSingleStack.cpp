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
void postorderTraversal(Node *root)
{
    stack<Node*> st;
    Node* curr = root;
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
                curr = temp;
        }
    }
}
int main()
{
    Node *root = NULL;
    root = insertRoot(root, 1);
    root = insertBNTree(root, 1, 2);
    root = insertBNTree(root, 1, 3);
    root = insertBNTree(root, 2, 4);
    root = insertBNTree(root, 2, 11);
    root = insertBNTree(root, 3, 10);

    postorderTraversal(root);
    return 0;
}