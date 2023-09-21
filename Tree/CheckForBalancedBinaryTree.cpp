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
void traversal(Node *root)
{
    stack<pair<Node*, int>> st;
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        auto node = it.first;
        auto val = it.second;
        if(val == 1){
            preorder.push_back(node->data);
            st.push({node, ++val});
            if(node->left != NULL)
                st.push({node->left, 1});
        }
        else if(val == 2){
            inorder.push_back(node->data);
            st.push({node, ++val});
            if(node->right != NULL)
                st.push({node->right, 1});
        }
        else if(val == 3){
            postorder.push_back(node->data);
        }
    }

    for(auto it : inorder)
        cout << it << " ";

    cout << endl;

    for(auto it : preorder)
        cout << it << " ";

    cout << endl;

    for(auto it : postorder)
        cout << it << " ";

}
int checkHeight(Node* root){
    if(root == NULL)
        return 0;
    
    int lheight = checkHeight(root->left);
    if(lheight == -1)
        return -1;
    
    int rheight = checkHeight(root->right);
    if(rheight == -1)
        return -1;

    if(abs(lheight - rheight) > 1)
        return -1;
    
    return  1 + max(lheight, rheight);
}
bool isBalanced(Node* root){
    return checkHeight(root) != -1;
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
    traversal(root);
    cout << endl << isBalanced(root);
    return 0;
}