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
int lengthLL(Node* head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head->next;
    }
    return length;
}

// Recursive Solution
Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;

    // Traverse to k nodes
    for(int i=0; i<k; i++){
        if(temp == NULL)
            return head;
        
        temp = temp->next;
    }

    // Reverse from head to K
    Node* prev = NULL;
    Node* ptr = NULL;
    temp = head;
    for(int i=0; i<k; i++){
        ptr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ptr;
    }

    // Now, head will be reversed as well, so we attach the next link to head
    if(ptr != NULL)
        head->next = reverseKGroup(ptr, k);
    return prev;
}

// Iterative Solution
Node* reverseNodesKGroup(Node* head, int k){
    if(head == NULL || head->next == NULL)
        return head;
    
    int length = lengthLL(head);
    Node* d = new Node(0);
    Node* pre = d;
    Node* curr;
    Node* nex;

    d->next = head;
    while(length >= k){
        curr = pre->next;
        nex = curr->next;
        for(int i=1; i<k; i++){
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        length -= k;
    }
    return d->next;
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
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    showLL(head);
    head = reverseNodesKGroup(head, 2);
    cout << endl;
    showLL(head);
}