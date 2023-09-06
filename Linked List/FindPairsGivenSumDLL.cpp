#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* insertDLL(Node* head, int val){
    if(head == NULL)
        return new Node(val);
    
    Node* ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = new Node(val);
    ptr->next->prev = ptr;
    return head;
}
vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> ans;
    Node* start = head;
    Node* end = head;
    while(end->next != NULL)
        end = end->next;

    
    while(start != end && (start->prev != end && end->next != start)){
        int val = start->data + end->data;
        if(val == k){
            ans.push_back(make_pair(start->data, end->data));
            start = start->next;
            end = end->prev;
        }
        else if(val > k)
            end = end->prev;
        else
            start = start->next;
    }
    return ans;
}
void showDLL(Node* head){
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
    head = insertDLL(head, 1);
    head = insertDLL(head, 2);
    head = insertDLL(head, 3);
    head = insertDLL(head, 4);
    head = insertDLL(head, 9);
    showDLL(head);
    cout << endl;
    auto ans = findPairs(head, 5);
    for(auto it : ans)
        cout << it.first << "-" << it.second << endl;
}