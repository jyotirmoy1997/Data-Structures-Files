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
bool isIdentical(Node* p, Node* q){
    if(p == NULL || q == NULL)
        return p == q;

    return (p->data == q->data) && (isIdentical(p->left, q->left)) && (isIdentical(p->right, q->right));
}
int main()
{
    Node *root1 = NULL;
    root1 = insertRoot(root1, 1);
    root1 = insertBNTree(root1, 1, 2);
    root1 = insertBNTree(root1, 1, 3);
    root1 = insertBNTree(root1, 2, 4);
    root1 = insertBNTree(root1, 2, 11);
    root1 = insertBNTree(root1, 3, 10);
    // traversal(root1);

    Node *root2 = NULL;
    root2 = insertRoot(root2, 1);
    root2 = insertBNTree(root2, 1, 2);
    root2 = insertBNTree(root2, 1, 3);
    root2 = insertBNTree(root2, 2, 4);
    root2 = insertBNTree(root2, 2, 11);
    root2 = insertBNTree(root2, 3, 12);
    // traversal(root2);

    cout << isIdentical(root1, root2);
    return 0;
}