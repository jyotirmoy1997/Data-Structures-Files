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
Node* deleteDuplicates(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* dummyHead = new Node(101);
    Node* temp = dummyHead;
    temp->next = head;
    Node* ptr = head;
    Node* ptr2 = head->next;
    while(ptr2 != NULL){
        bool flag = false;
        while(ptr2 != NULL && ptr->data == ptr2->data){
            ptr2 = ptr2->next;
            flag = true;
        }
        if(flag){
            temp->next = ptr2;
        }
        else{
            ptr->next = ptr2;
            temp = ptr;
        }
        ptr = ptr2;
        if(ptr2 != NULL)
            ptr2 = ptr2->next;
    }
    head = dummyHead->next;
    dummyHead->next = NULL;
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
int main(){
    Node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 4);
    head = insert(head, 5);
    showLL(head);
    head = deleteDuplicates(head);
    cout << endl;
    showLL(head);
}