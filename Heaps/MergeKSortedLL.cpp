/* Approach => The Idea is to use a min heap to store the min element
at each iteration. */

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
struct compare{
    bool operator()(Node* a, Node*b){
        return a->data > b->data;
    }
};
Node* mergeKLists(vector<Node*> &lists) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    int k = lists.size();
    if(k == 0)
        return NULL;

    for(int i=0; i<k; i++){
        if(lists[i] != NULL)
            pq.push(lists[i]);
    }

    Node* head = NULL;
    Node* tail = NULL;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();

        if(node->next != NULL)
                pq.push(node->next);

        if(head == NULL){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }
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
	Node* head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(5);

    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    Node* head3 = new Node(2);
    head3->next = new Node(6);

    vector<Node*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    Node* headCombined = mergeKLists(lists);
    showLL(headCombined);
}
