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
int loopLength(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* slow2 = head;
    bool flag = false;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        slow2 = slow2->next;
        fast = fast->next->next;
        if(fast == slow){
            flag = true;
            break;
        } 
    }
    if(flag){
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        while(slow2->next != slow)
            slow2 = slow2->next;

        int count = 1;
        while(fast != slow2){
            fast = fast->next;
            count++;
        }
        return count;
    }
    return -1;
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
    Node* lh = tail(head);
    head = insert(head, 2);
    head = insert(head, 3);
    Node* tailPtr = tail(head);
    tailPtr->next = lh;
    
    cout << loopLength(head);
}