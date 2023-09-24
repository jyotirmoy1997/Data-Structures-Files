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
string serialize(Node* root){
    queue<Node*> q;
    string s = "";
    if(root == NULL)
        return s;
    
    q.push(root);
    s += to_string(root->data) + ">";
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node->left != NULL){
            q.push(node->left);
            s += to_string(node->left->data) + ">";
        }
        else
            s += "#>";
        if(node->right != NULL){
            q.push(node->right);
            s += to_string(node->right->data) + ">";
        }
        else
            s += "#>";
    }
    return s;
}
Node* desRec(vector<int> &data, int index, int size){
    if(index > size || data[index] > 1000)
        return NULL;

    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    Node* root = new Node(data[index]);

    root->left = desRec(data, leftIndex, size);
    root->right = desRec(data, rightIndex, size);

    return root;

}
Node* deserialize(string data){
    vector<int> ds;
    string s = "";
    // cout << data << endl;
    for(int i=0; i<data.length(); i++){
        if(data[i] != '>')
            s += data[i];
        else{
            // cout << s << " ";
            if(s[0] == '#')
                ds.push_back(1500);
            else
                ds.push_back(stoi(s));
            s = "";
        }
    }
    for(auto it : ds)
        cout << it << " ";

    // Node* root = desRec(ds, 0, ds.size());
    // return root;

}
void inOrder(Node* root){
    if(root == NULL)
        return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    Node *root = new Node(-1000);
    // root->left = new Node(2);
    // root->right = new Node(300);
    // // root->left->left = new Node(1);
    // // root->left->right = new Node(3);
    // root->right->left = new Node(-4);
    // root->right->right = new Node(5);
 
    string s = serialize(root);
    
    cout << s << endl;
    deserialize(s);

    // inOrder(root2);
    

    // cout << INT_MAX;

    // string s1 = "-1204";
    // cout << stoi(s1);

    // vector<int> vec;

    // // string s = "123456";
    // for(int i=0; i<s.length(); i++){
    //     vec.push_back(s[i] - 48); 
    // }

    // for(auto it : vec)
    //     cout << it << " ";
}