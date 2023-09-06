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
Node* tail(Node* head){
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr;
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
Node* intersectionPoint(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL)
        return NULL;

    Node* curr1 = head1;
    Node* curr2 = head2;

    while(curr1 != curr2){
        curr1 = (curr1 == NULL) ? head2 : curr1->next;
        curr2 = (curr2 == NULL) ? head1 : curr2->next;
    }

    return curr1;
    
}
int main()
{
    Node* head1 = NULL;
    head1 = insert(head1, 2);
    head1 = insert(head1, 8);
    head1 = insert(head1, 1);
    head1 = insert(head1, 3);
    head1 = insert(head1, 8);

    Node* intPoint = tail(head1);
    
    head1 = insert(head1, 7);
    head1 = insert(head1, 6);

    Node* head2 = NULL;
    head2 = insert(head2, 1);
    head2 = insert(head2, 2);

    // showLL(head2);

    Node* tail2 = tail(head2);
    tail2->next = intPoint;

    showLL(head1);
    cout << endl;
    showLL(head2);
    cout << endl;
    

    Node* res = intersectionPoint(head1, head2);
    cout << res->data;
}