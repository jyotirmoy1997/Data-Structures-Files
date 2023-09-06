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
void showLL(Node* head){
    if(head == NULL)
        return;
    
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
Node* mergeList(Node* l1, Node* l2){
    Node* d = new Node(0);
    Node* curr = d;

    while(l1 != NULL && l2 != NULL){
        if(l1->data <= l2->data){
            curr->next = l1;
            l1 = l1->next;
        }
        else{
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    while(l1 != NULL){
        curr->next = l1;
        l1 = l1->next;
        curr = curr->next;
    }

    while(l2 != NULL){
        curr->next = l2;
        l2 = l2->next;
        curr = curr->next;
    }

    return d->next;
}
Node* sortList(Node* head){
    if(head == NULL || head->next == NULL)
        return head;

    Node* temp = NULL;
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    temp->next = NULL;

    Node* l1 = sortList(head);
    Node* l2 = sortList(slow);

    return mergeList(l1, l2);
}
int main()
{
    Node* head = NULL;
    head = insert(head, 6);
    head = insert(head, 7);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 3);
    showLL(head);
    head = sortList(head);
    cout << endl;
    showLL(head);
}