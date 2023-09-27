#include<iostream>
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
Node* mergeTwoSortedLists(Node* h1, Node* h2){
    Node* d = new Node(0);
    if(h1->data > h2->data)
        d->next = h1;
    
    else
        d->next = h2;
    
    Node* p1 = h1;
    Node* p2 = h2;
    Node* curr = d;
    while(p1 != NULL && p2 != NULL){
        if(p1->data > p2->data){
            curr->next = p2;
            p2 = p2->next;
        }
        else{
            curr->next = p1;
            p1 = p1->next;
        }
        curr = curr->next;
    }
    if(p1 == NULL)
        curr->next = p2;
    
    else if(p2 == NULL)
        curr->next = p1;
    
    Node* head = d->next;
    d->next = NULL;
    return head;
}
int main()
{
    Node* head1 = NULL;
    head1 = insert(head1, 2);
    head1 = insert(head1, 5);
    head1 = insert(head1, 11);
    head1 = insert(head1, 22);
    head1 = insert(head1, 34);
    showLL(head1);
    cout << endl;

    Node* head2 = NULL;
    head2 = insert(head2, 6);
    head2 = insert(head2, 4);
    head2 = insert(head2, 9);
    head2 = insert(head2, 18);
    head2 = insert(head2, 26);
    showLL(head2);
    cout << endl;

    Node* h3 = mergeTwoSortedLists(head1, head2);
    showLL(h3);
}