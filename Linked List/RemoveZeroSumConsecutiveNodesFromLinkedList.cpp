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
ListNode* removeZeroSumSublists(ListNode* head) {
    // Create a temporary node with value 0 pointing to the start of the head.
    ListNode* temp = new ListNode(0);
    temp->next = head;
    
    // Set prefix to 0 and define a map for storing prefix sums and their corresponding nodes.
    int prefix = 0;
    unordered_map<int, ListNode*> prefixMap;

    prefixMap[0] = temp;

    // Update the prefix sums and map the values. If any value repeats, it means the sequence in between sums to 0 and can be ignored.
    while (head != NULL) {
        prefix += head->val;
        prefixMap[prefix] = head;
        head = head->next;
    }

    // Reset head to the temporary node and prefix to 0.
    head = temp;
    prefix = 0;

    // Remove the sequences with sum = 0.
    while (head != NULL) {
        prefix += head->val;
        head->next = prefixMap[prefix]->next;
        head = head->next;
    }

    return temp->next;
}
int main(){

}