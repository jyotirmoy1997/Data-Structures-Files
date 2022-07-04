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
Node* insert(Node *head, int val)
{
    if(head == NULL)
    {
        return new Node(val);
    }
    else
    {
        Node *ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new Node(val);
    }
    return head;
}
Node* insertCircular(Node *head, int val)
{
    if(head == NULL)
    {
        return new Node(val);
    }
    else if(head->next == NULL)
    {
        Node *newNode = new Node(val);
        head->next = newNode;
        newNode->next = head;
    }
    else
    {
        Node *ptr = head;
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }
        Node *ptr2 = new Node(val);
        ptr->next = ptr2;
        ptr2->next = head;
    }
    return head;
}
Node* deletefirst(Node *head)
{
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
Node* deletelast(Node *head)
{
    Node *ptr = head, *ptr2 = head->next;
    while(ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(ptr2);
    return head;

}
void display(Node *head)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
}
void displayCircular(Node *head)
{
    Node *ptr = head;
    int c = 0;
    do
    {
        cout << ptr->data << " [" << &ptr->next << "] -> ";
        ptr = ptr->next;
        c++;
    }while(c < 10);
}
Node* reverseRecursive(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseRecursive(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = NULL;
    return newHead;
}
int main()
{
    Node *header = NULL;
    header = insert(header, 5);
    insert(header, 8);
    insert(header, 9);
    insert(header, 3);
    insert(header, 4);
    display(header);
    header = reverseRecursive(header);

    // header = deletelast(header);
    cout << endl;
    display(header);
    // cout << &header;
    // Node *circheader = NULL;
    // circheader = insertCircular(circheader, 8);
    // insertCircular(circheader, 9);
    // insertCircular(circheader, 10);
    // insertCircular(circheader, 11);
    // insertCircular(circheader, 18);
    // displayCircular(circheader);
}