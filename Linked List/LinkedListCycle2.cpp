#include<bits/stdc++.h>
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

// Optimal Approach => Use Two Pointers - fast and slow
Node* loopStart(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool flag = false;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            flag = true;
            break;
        }
            
    }
    if(!flag)
        return NULL;
    
    fast = head;
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// 
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
    Node* lh = tail(head);
    head = insert(head, 2);
    head = insert(head, 3);
    Node* tailPtr = tail(head);
    tailPtr->next = lh;
    Node* temp = loopStart(head);
    cout << temp->data;
}