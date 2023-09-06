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
Node* deleteAllOcc(Node* head, int val){
    if(head == NULL)
        return NULL;

    while(head->data == val)
        head = head->next;

    if(head != NULL && head->next != NULL){
        head->prev = NULL;
        Node* ptr = head;
        Node* ptr2 = head->next;
        while(ptr2 != NULL){
            while(ptr2 != NULL && ptr2->data == val)
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
    head = insertDLL(head, 10);
    head = insertDLL(head, 4);
    head = insertDLL(head, 10);
    head = insertDLL(head, 3);
    head = insertDLL(head, 10);
    head = insertDLL(head, 10);
    // head = insertDLL(head, 5);
    // head = insertDLL(head, 20);
    showDLL(head);
    cout << endl;
    head = deleteAllOcc(head, 10);
    showDLL(head);
    
}