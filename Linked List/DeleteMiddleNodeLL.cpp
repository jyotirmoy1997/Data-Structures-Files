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

// We are using the Tortoise Hare Method. 

Node* deleteMiddleNode(Node* head){
    if(head == NULL || head->next == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    Node* temp = NULL;
    while(fast->next != NULL && fast != NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = slow->next;
    return head;
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
    auto node = deleteMiddleNode(head);
    cout << endl << node->data;
}