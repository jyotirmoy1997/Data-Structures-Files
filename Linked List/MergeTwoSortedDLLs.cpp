#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* insertDLL(Node* head, int val){
    if(head == NULL)
        return new Node(val);
    
    Node* ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = new Node(val);
    ptr->next->prev = ptr;
    return head;
}
Node* mergeSortedDLL(Node* h1, Node* h2){
    Node* d = new Node(0);
    if(h1->data > h2->data)
        d->next = h2;

    else
        d->next = h1;

    Node* p1 = h1;
    Node* p2 = h2;
    Node* curr = d;
    while(p1 != NULL && p2 != NULL){
        if(p1->data > p2->data){
            curr->next = p2;
            p2->prev = curr;
            p2 = p2->next;
        }
        else{
            curr->next = p1;
            p1->prev = curr;
            p1 = p1->next;
        }
        curr = curr->next;
    }
    if(p1 == NULL){
        curr->next = p2;
        p2->prev = curr;
    }
        
    else if(p2 == NULL){
        curr->next = p1;
        p1->prev = curr;
    }
        
    Node* head = d->next;
    d->next = NULL;
    head->prev = NULL;
    return head;
}
void showDLL(Node* head){
    if(head == NULL)
        return;

    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
        
}
int main()
{
    Node* h1 = NULL;
    h1 = insertDLL(h1, 2);
    h1 = insertDLL(h1, 8);
    h1 = insertDLL(h1, 10);
    showDLL(h1);
    cout << endl;

    Node* h2 = NULL;
    h2 = insertDLL(h2, 7);
    h2 = insertDLL(h2, 9);
    h2 = insertDLL(h2, 11);
    showDLL(h2);
    cout << endl;
    
    Node* h3 = mergeSortedDLL(h1, h2);
    showDLL(h3);
}