#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val)
    {
        val = val;
        next = NULL;
    }
};
ListNode* mergeNodes(ListNode* head){
    ListNode* ptr = head;
    ListNode* ptr2 = head->next;
    while(ptr2 != NULL){
        int sum = 0;
        while(ptr2->val != 0){
            sum += ptr2->val;
            ptr2 = ptr2->next;
        }
        ptr->val = sum;
        ptr->next = (ptr2->next == NULL) ? NULL : ptr2;
        ptr = (ptr2->next == NULL) ? ptr : ptr2;
        ptr2 = ptr2->next;
    }
    return head;
}
int main(){

}