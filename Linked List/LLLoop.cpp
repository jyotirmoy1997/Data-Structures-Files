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

// Brute Force Approach => Uses Hashing
Node* detectLoopBrute(Node* head){
    unordered_map<Node*, int> mpp;
    Node* ptr = head;
    Node* temp = NULL;
    while(ptr != NULL){
        if(mpp.find(ptr) != mpp.end()){
            temp = ptr;
            break;
        }
        mpp[ptr] = ptr->data;
        ptr = ptr->next;
    }
    return temp;
}

// Optimal Approach => Use Two Pointers - fast and slow
bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return true;
    }
    return false;
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
    
    cout << detectLoop(head);
}