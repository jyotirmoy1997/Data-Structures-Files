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
// The Slow Pointer Moves exaactly once, The Fast Pointer moves exactly twice.
// The momment Fast pointer points to the last node or crosses the last node, the 
// slow pointer will always point to the middle element
Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    auto node = middleNode(head);
    cout << endl << node->data;
}