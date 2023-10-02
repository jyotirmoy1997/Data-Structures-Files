#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* bottom;
    Node(int val){
        data = val;
        next = NULL;
        bottom = NULL;
    }
};
Node* mergeTwoSortedLists(Node* h1, Node* h2){
    Node* d = new Node(0);
    if(h1->data > h2->data)
        d->bottom = h1;
    
    else
        d->bottom = h2;
    
    Node* p1 = h1;
    Node* p2 = h2;
    Node* curr = d;
    while(p1 != NULL && p2 != NULL){
        if(p1->data > p2->data){
            curr->bottom = p2;
            p2 = p2->bottom;
        }
        else{
            curr->bottom = p1;
            p1 = p1->bottom;
        }
        curr = curr->bottom;
    }
    if(p1 == NULL)
        curr->bottom = p2;
    
    else if(p2 == NULL)
        curr->bottom = p1;
    
    Node* head = d->bottom;
    d->bottom = NULL;
    return head;
}
Node* flattenLL(Node* head){
    if(head->next == NULL)
        return head;

    Node* head2 = flattenLL(head->next);
    head->next = NULL;
    Node* head3 = mergeTwoSortedLists(head, head2);
    return head3;
}
void showLL(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        Node* curr = ptr->bottom;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->bottom;
        }
        ptr = ptr->next;
        cout << endl;
    }
}
int main()
{
    Node* head = new Node(5);

    // LL 1 
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    // LL 2 
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    

    // LL 3
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    // LL 4
    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    showLL(head);
    cout << endl;

    Node* h2 = flattenLL(head);
    showLL(h2);
}