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
Node* reverse(Node* head){

}
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
bool isPalindrome(Node* head){
    if(head == NULL || head->next != NULL)
        return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // cout << slow->data;
    // showLL(head);
    // Node* slow2 = slow;
    Node* revHead = reverseLL(slow->next);
    // cout << revHead->data;
    // showLL(head);
    slow->next = revHead;
    fast = head;
    while(revHead != NULL){
        if(revHead->data != fast->data)
            return false;
        revHead = revHead->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    Node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);
    cout << isPalindrome(head);
}