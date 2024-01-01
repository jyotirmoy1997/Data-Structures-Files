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
pair<Node*, Node*> reverseLL(Node* head, Node* end){
    Node* tail = head;
    Node* temp = NULL;
    Node* ptr = head;
    Node* ptr2 = head->next;
    while(ptr2 != end){
        ptr->next = temp;
        temp = ptr;
        ptr = ptr2;
        ptr2 = ptr2->next;
    }
    ptr->next = temp;
    return {ptr, tail};
}
Node* reverseBetween(Node* head, int left, int right){
    int pos = 0;
    Node* start = NULL;
    Node* headStart = NULL;
    Node* end = NULL;
    Node* ptr = head;
    Node* temp = NULL;
    while(ptr != NULL){
        pos++;
        if(pos == left){
            start = ptr;
            headStart = temp;
        }
        if(pos == right)
            end = ptr->next;
        
        temp = ptr;
        ptr = ptr->next;
    }
    auto nodes = reverseLL(start, end);
    nodes.second->next = end;

    if(headStart != NULL)
        headStart->next = nodes.first;
    
    else if(headStart == NULL)
        head = nodes.first;
    
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
}