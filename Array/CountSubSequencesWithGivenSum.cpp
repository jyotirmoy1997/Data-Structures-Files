/* Given an arrays, the task is to count the sub sequences that adds up to the given sum.
Here, in each call, we either take the element or we don't take the element.


Time Complexity => O(2^n)
Space Cmplexity => O(n) // Recursion Tree Depth

 */

#include<bits/stdc++.h>
using namespace std;
int printSubSequences(int index, int s, int arr[], int n, int sum){
    if(index == n){
        if(s == sum)
            return 1;
        return 0;
    }

    // In this call, we are taking the element
    s += arr[index];
    int l = printSubSequences(index+1, s, arr, n, sum);

    // In this call, we are not taking the element
    s -= arr[index];
    int r = printSubSequences(index+1, s, arr, n, sum);

    return l + r;
}
int main(){
    int arr[] = {3, 1, 2};
    cout << printSubSequences(0, 0, arr, sizeof(arr)/sizeof(int), 3);
}