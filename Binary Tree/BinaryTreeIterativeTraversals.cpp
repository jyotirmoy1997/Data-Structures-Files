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
    stack<Node*> st;
    Node* temp = root;
    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty())
                break;
            
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}
void preorderTraversal(Node *root)
{
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        cout << node->data << " ";

        if(node->right != NULL)
            st.push(node->right);

        if(node->left != NULL)
            st.push(node->left);
        
    }
}
void postorderTraversal(Node *root)
{
    stack<Node*> st1;
    stack<int> st2;
    st1.push(root);
    while(!st1.empty()){
        auto node = st1.top();
        st1.pop();
        if(node->left != NULL)
            st1.push(node->left);

        if(node->right != NULL)
            st1.push(node->right);   
        
        st2.push(node->data);
    }
    while(!st2.empty()){
        cout << st2.top() << " ";
        st2.pop();
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

    inorderTraversal(root);

    cout << endl;
    preorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    return 0;
}