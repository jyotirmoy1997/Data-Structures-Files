#include<iostream>
#include<queue>
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
int height(Node *r)
{
    if(r == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = height(r->left);
        int rheight = height(r->right);
        if(lheight > rheight)
        {
            return lheight+1;
        }
        else
        {
            return rheight+1;
        }
    }
}
int getBalanceFactor(Node *n)
{
    if(n == NULL)
    {
        return -1;
    }
    else
    {
        return (height(n->left) - height(n->right));
    }
}
Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;
    x->right = y;
    y->left = temp;
    return x;
}
Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;
    y->left = x;
    x->right = temp;
    return y;
}
Node* insertAVL(Node *root, int val)
{
    if(root == NULL)
    {
      return new Node(val);
    }
    if(val < root->data)
    {
      root->left = insertAVL(root->left, val);
    }
    else
    {
      root->right = insertAVL(root->right, val);
    }
    int bf = getBalanceFactor(root);
    if((bf > 1) && (val < root->left->data))
    {
        return rightRotate(root);
    }
    else if((bf < -1) && (val > root->right->data))
    {
        return leftRotate(root);
    }
    else if((bf > 1) && (val > root->left->data))
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if((bf < -1) && (val < root->right->data))
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
Node* inorderSuccesor(Node *root)
{
  Node *current = root;
  while(current && current->left != NULL)
  {
    current = current->left;
  }
  return current;
}
Node* deleteAVL(Node *root, int val)
{
    if(val < root->data)
    {
      root->left = deleteAVL(root->left, val);
    }
    else if(val > root->data)
    {
      root->right = deleteAVL(root->right, val);
    }
    else
    {
      if(root->left == NULL)
      {
        Node *temp = root->right;
        free(root);
        return temp;
      }
      else if(root->right == NULL)
      {
        Node *temp = root->right;
        free(root);
        return temp;
      }
      else
      {
          Node *temp = inorderSuccesor(root->right);
          root->data = temp->data;
          root->right = deleteAVL(root->right, temp->data);
      }
       
    }
    int bf = getBalanceFactor(root);
    if((bf == 2) && (getBalanceFactor(root->left) >= 0))
    {
        return rightRotate(root);
    }
    else if((bf == 2) && (getBalanceFactor(root->left) == -1))
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if((bf == -2) && (getBalanceFactor(root->right) <= 0))
    {
        return leftRotate(root);
    }
    else if((bf == -2) && (getBalanceFactor(root->right) == 1))
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(Node *root)
{
  if(root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void levelorder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }   

    }
}
int main()
{
    Node *root = NULL;
    root = insertAVL(root, 10);
    root = insertAVL(root, 20);
    root = insertAVL(root, 15);
    // root = insertAVL(root, 8);
    // root = insertAVL(root, 9);
    // root = insertAVL(root, 20);
    // root = insertAVL(root, 25);
    // root = insertAVL(root, 22);
    // root = insertAVL(root, 35);
    // root = insertAVL(root, 45);
    // root = insertAVL(root, 32);
    levelorder(root);
    // root = deleteAVL(root, 45);
    cout << endl;
    //levelorder(root);
}