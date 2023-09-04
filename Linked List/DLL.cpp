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
Node* deleteNodeDLL(Node* head, int val){
    if(head->next == NULL && head->data == val){
        free(head);
        return NULL;
    }  
    if(head->data == val){
        Node* ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        return head;
    }
    Node* ptr = head->next;
    while(ptr->data != val && ptr->next != NULL){
        ptr = ptr->next;
    }
    if(ptr->data == val && ptr->next != NULL){
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    else if(ptr->data == val && ptr->next == NULL){
        ptr->prev->next = NULL;
        free(ptr);
    }
    return head;
}
Node* reverseDLL(Node* head){
    if(head == NULL)
        return NULL;
    
    if(head->next == NULL)
        return head;

    Node* ptr = head;
    Node* temp = NULL;
    while(ptr != NULL){
        ptr->prev = ptr->next;
        ptr->next = temp;
        temp = ptr;
        ptr = ptr->prev;
    }
    return temp;
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
    head = insertDLL(head, 6);
    head = insertDLL(head, 7);
    head = insertDLL(head, 1);
    head = insertDLL(head, 2);
    head = insertDLL(head, 3);
    showDLL(head);
    head = reverseDLL(head);
    cout << endl;
    showDLL(head);
}