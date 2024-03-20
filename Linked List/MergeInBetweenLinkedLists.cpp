#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int d){
        val = d;
        next = NULL;
    }
};
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *currNode = list1;
    int index = 0;
    while(index < a-1){
        currNode = currNode->next;
        index++;
    }
    ListNode *front = currNode;
    while(index < b+1){
        currNode = currNode->next;
        index++;
    }
    ListNode *rear = currNode;
    ListNode *secondListTail = list2, *secondListHead = list2;
    while(secondListTail->next != NULL)
        secondListTail = secondListTail->next;

    front->next = secondListHead;
    secondListTail->next = rear;
    return list1;
}
int main(){
    ListNode *l1 = new ListNode(10);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(13);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(100001);
    l2->next = new ListNode(100002);
    l2->next->next = new ListNode(100003);

    int a = 3, b = 5;
    l1 = mergeInBetween(l1, a, b, l2);
}