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
Node* rotateRight(Node* head, int k){
  if(head == NULL || head->next == NULL)
        return head;
    
  int length = 0;
  Node* ptr = head;
  
  while(ptr->next != NULL){
      ptr = ptr->next;
      length++;
  }
  length++;
  k = k % length;
  ptr->next = head;
  int count = 0;
  while(count != length - k){
      ptr = ptr->next;
      count++;
  }
  head = ptr->next;
  ptr->next = NULL;
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
    cout << endl;
    head = rotateRight(head, 2);
    showLL(head);
}