#include<bits/stdc++.h>
using namespace std;
vector<pair<char, string>> res;
struct Node
{
    char character;
    int freq;
    Node *left, *right;
    Node(char c, int v)
    {
        character = c;
        freq = v;
        left = NULL;
        right = NULL;
    }
};
struct compare
{
    bool operator()(Node *a, Node *b)
    {
        if(a->freq > b->freq)
        {
            return true;
        }
        return false;
    }
};
Node* createHuffmanTree(vector<pair<char, int>> arr)
{
    priority_queue<Node*, vector<Node*>, compare> pq;
    for(auto it : arr)
    {
        pq.push(new Node(it.first, it.second));
    }
    
    while(pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *temp = new Node('#', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }
    Node *root = pq.top();
    pq.pop();
    return root;
}
void generateCodes(Node *root, string str)
{
    if(root->left == NULL || root->right == NULL)
    {
        // cout << root->character << " ";
        res.push_back(make_pair(root->character, str));
        return;
    }
    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}
int main()
{
    vector<pair<char, int>> arr;
    int n;
    cout << "Enter number of characters :: ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int f;
        char c;
        cout << "Enter character :: ";
        cin >> c;
        cout << "Enter frequency :: ";
        cin >> f;
        arr.push_back(make_pair(c, f));
    }
    Node *root = createHuffmanTree(arr);
    generateCodes(root, "");
    for(auto it : res)
    {
        cout << it.first << " - " << it.second << endl;
    }
}