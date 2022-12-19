/* Given an arrays, the task is to find all the sub sequences that totals to a given sum.
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
void printSubSequences(int index, vector<int> &vec, int arr[], int n, int s, int sum){
    if(index == n){
        if(s == sum){
            printArray(vec);

        }
        return;
    }

    // In this call, we are taking the element
    vec.push_back(arr[index]);
    s += arr[index];
    printSubSequences(index+1, vec, arr, n, s, sum);\

    // In this call, we are not taking the element
    s -= arr[index];
    vec.pop_back();
    printSubSequences(index+1, vec, arr, n, s, sum);
}
int main(){
    int arr[] = {3, 1, 2};
    vector<int> vec;
    printSubSequences(0, vec, arr, sizeof(arr)/sizeof(int), 0, 3);
}