/*
    Approach => Create a dummy node and let that node point to the head
    Create two dummy pointers => fast and Slow
    Move fast pointer to n places
    Move slow pointer and fast pointer simultaneously until fast pointer reaches the last node
    Now slow pointer points to the node to be deleted
    Delete the node and return the next of the dummy node

*/


#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* insert(Node* head, int val){
    if(head == NULL)
        return new Node(val);
    
    Node* ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = new Node(val);
    return head;
}
void showLL(Node* head){
    if(head == NULL)
        return;
    
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
Node* removeNthLastNode(Node* head, int n){
    Node* d = new Node(-1);
    d->next = head;
    Node* fast = d;
    Node* slow = d;

    for(int i=1; i<=n; i++)
        fast = fast->next;

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return d->next;
}
int main()
{
    Node* head = NULL;
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    showLL(head);
    head = removeNthLastNode(head, 2);
    cout << endl;
    showLL(head);
}