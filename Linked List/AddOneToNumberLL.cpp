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
Node* reverseLL(Node* head){
    Node* temp = NULL;
    Node* ptr = head;
    Node* ptr2 = head->next;
    while(ptr2 != NULL){
        ptr->next = temp;
        temp = ptr;
        ptr = ptr2;
        ptr2 = ptr2->next;
    }
    ptr->next = temp;
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
Node* addOneNumber(Node* head){
    int carry = 1;
    head = reverseLL(head);
    Node* temp = head;
    Node* temp2 = NULL;
    while(carry > 0){
        if(temp != NULL){
            int val = temp->data;
            temp->data = (val + carry) % 10;
            carry = (val + carry) / 10;
            temp2 = temp;
            temp = temp->next;
        }
        else if(temp == NULL){
            Node* newNode = new Node(carry);
            carry = 0;
            temp2->next = newNode;
        }
    }
    head = reverseLL(head);
    return head;
}

int main()
{
    Node* head1 = NULL;
    head1 = insert(head1, 9);
    head1 = insert(head1, 9);
    head1 = insert(head1, 0);

    head1 = addOneNumber(head1);
    showLL(head1);
}