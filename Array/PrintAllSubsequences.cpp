/* Given an arrays, the task is to find all the sub sequences.
Here, in each call, we either take the element or we don't take the element.


Time Complexity => O(2^n)
Space Cmplexity => O(n) // Recursion Tree Depth

 */

#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> &vec){
    for(auto it : vec){
        cout << it << " ";
    }
    cout << endl;
}
void printSubSequences(int index, vector<int> &vec, int arr[], int n){
    if(index == n){
        printArray(vec);
        return;
    }

    // In this call, we are taking the element
    vec.push_back(arr[index]);
    printSubSequences(index+1, vec, arr, n);\

    // In this call, we are not taking the element
    vec.pop_back();
    printSubSequences(index+1, vec, arr, n);
}
int main(){
    int arr[] = {3, 1, 2};
    vector<int> vec;
    printSubSequences(0, vec, arr, sizeof(arr)/sizeof(int));
}