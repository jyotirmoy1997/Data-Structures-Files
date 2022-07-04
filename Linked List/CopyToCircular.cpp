#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node* insert(Node *head, int data)
{
    if(head == NULL)
    {
        return new Node(data);
    }
    Node *new_node = new Node(data);
    Node *ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next; 
    }
    ptr->next = new_node;
    new_node->next = NULL;
    return head;
}
void traverseCircular(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next; 
    }while(ptr != head);
}
Node* copyToCircular(Node *head1, Node *head2)
{
    Node *ptr = head1;
    head2 = new Node(ptr->data);
    Node *ptr2 = head2;
    ptr = ptr->next;
    while(ptr != NULL)
    {
        Node *new_node = new Node(ptr->data);
        ptr2->next = new_node;
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }
    ptr2->next = head2;
    return head2;
}
void traverse(Node *head)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next; 
    }
}
int main()
{
    Node *header = NULL;
    header = insert(header, 2);
    header = insert(header, 3);
    header = insert(header, 5);
    header = insert(header, 8);
    header = insert(header, 10);
    header = insert(header, 12);
    traverse(header);
    Node *circular = NULL;
    circular = copyToCircular(header, circular);
    cout << endl;
    traverseCircular(circular);
}