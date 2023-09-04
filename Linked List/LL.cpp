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
Node* deleteNode(Node* head, int val){
    if(head->next == NULL && head->data == val){
        free(head);
        return NULL;
    }  
    if(head->data == val){
        Node* ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }
    Node* ptr = head;
    Node* ptr2 = head->next;
    while(ptr2->data != val && ptr2->next != NULL){
        ptr = ptr2;
        ptr2 = ptr2->next;
    }
    if(ptr2->data == val){
        ptr->next = ptr2->next;
        free(ptr2);
    }
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
int main()
{
    Node* head = NULL;
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    showLL(head);
    head = deleteNode(head, 6);
    cout << endl;
    showLL(head);
}