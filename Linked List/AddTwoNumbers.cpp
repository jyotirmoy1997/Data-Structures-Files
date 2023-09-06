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
Node* addTwoNumbers(Node* head1, Node* head2){
    Node* d = new Node(0);
    Node* temp = d;
    int carry = 0;
    while(head1 != NULL || head2 != NULL || carry > 0){
        int sum = 0;
        if(head1 != NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node* newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
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
    Node* head1 = NULL;
    head1 = insert(head1, 2);
    head1 = insert(head1, 4);
    head1 = insert(head1, 3);

    Node* head2 = NULL;
    head2 = insert(head2, 5);
    head2 = insert(head2, 6);
    head2 = insert(head2, 4);

    Node* head3 = addTwoNumbers(head1, head2);
    
    showLL(head1);
    cout << endl;
    showLL(head2);
    cout << endl;
    showLL(head3);
}