/* Given an array, the task is to find the repeating element.

Constraints =>

1. arr[i] <= array size - 1
2. 0 is not allowed as an element 

Approach => Use the same method as the Linked List loop finding i.e. Two Pointer approach.
Move one pointer fast and other pointer slow.

*/

#include<bits/stdc++.h>
using namespace std;
int repeatingElement(int arr[], int n){
    int slow = arr[0], fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while(slow != fast);
    slow = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main(){
    int arr[] = {1, 3, 2, 4, 6, 5, 7, 3};
    cout << repeatingElement(arr, sizeof(arr)/sizeof(int));
}