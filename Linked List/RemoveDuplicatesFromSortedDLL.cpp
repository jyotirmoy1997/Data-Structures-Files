#include<bits/stdc++.h>
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
Node* removeDuplicates(Node* head){
    if(head == NULL || head->next == NULL)
        return head;

    while(head->next != NULL && head->data == head->next->data)
        head = head->next;
    
    if(head != NULL && head->next != NULL){
        head->prev = NULL;
        Node* ptr = head;
        Node* ptr2 = head->next;
        while(ptr2 != NULL){
            while(ptr2 != NULL && ptr->data == ptr2->data)
                ptr2 = ptr2->next;
            
            ptr->next = ptr2;
            if(ptr2 != NULL)
                ptr2->prev = ptr;
            ptr = ptr2;
            if(ptr2 != NULL)
                ptr2 = ptr2->next;
        }
    }
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
    Node* head = NULL;
    head = insertDLL(head, 1);
    head = insertDLL(head, 1);
    head = insertDLL(head, 1);
    head = insertDLL(head, 3);
    // head = insertDLL(head, 3);
    head = insertDLL(head, 4);
    head = insertDLL(head, 5);
    head = insertDLL(head, 5);
    head = insertDLL(head, 6);
    showDLL(head);

    head = removeDuplicates(head);
    cout << endl;
    showDLL(head);
}