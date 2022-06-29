#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *left, *right;
    Node(char c)
    {
        data = c;
        left = NULL;
        right = NULL;
    }
};
Node* buildExpressionTree(string expression)
{
    stack<Node*> st;
    for(auto it: expression)
    {
        // cout << it << " ";
        if(isdigit(it))
        {
            st.push(new Node(it));
        }
        else
        {
            if(!st.empty())
            {
                Node *right = st.top();
                st.pop();
                Node *left = st.top();
                st.pop();
                Node *temp = new Node(it);
                temp->right = right;
                temp->left = left;
                st.push(temp);
            }
        }
    }
    Node *root = st.top();
    st.pop();
    return root;

}
int evaluate(char op, int t1, int t2)
{
        // + => 43
        // - => 45
        // / => 47
        // * => 42
        // ^ => 94
        int val;
        if((int)op == 43) // Addition
        {
            val = t1 + t2;
        }
        else if((int)op == 45) // Subtraction
        {
            val = t1 - t2;
        }
        else if((int)op == 47) // Subtraction
        {
            val = t1 / t2;
        }
        else if((int)op == 42) // Subtraction
        {
            val = t1 * t2;
        }
        else if((int)op == 94) // Subtraction
        {
            val = (int)pow(t1, t2);
        }
        return val;
}
int evaluateExpressionTree(Node *root)
{
    Node *ptr = root;
    if(ptr != NULL)
    {
        Node *lptr = ptr->left;
        Node *rptr = ptr->right;
        int t1, t2, val;
        if(isdigit(lptr->data))
        {
            t1 = (int)lptr->data - 48;
        }
        else
        {
            t1 = evaluateExpressionTree(lptr);
        }
        if(isdigit(rptr->data))
        {
            t2 = (int)rptr->data - 48;
        }
        else
        {
            t2 = evaluateExpressionTree(rptr);
        }
        val = evaluate(ptr->data, t1, t2);
        return val;
    }
    return -1;
}
void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
int main()
{
    // 
    string expression = "234*+23*8+2/-";
    Node *root = buildExpressionTree(expression);
    // inorder(root);
    cout << evaluateExpressionTree(root);
}