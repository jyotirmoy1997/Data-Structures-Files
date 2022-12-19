/* Given an arrays, the task is to find the first sub sequences that totals to a given sum.
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
bool printSubSequences(int index, vector<int> &vec, int arr[], int n, int s, int sum){
    if(index == n){
        if(s == sum){
            printArray(vec);
            return true;
        }
        return false;
    }

    // In this call, we are taking the element
    vec.push_back(arr[index]);
    s += arr[index];
    if(printSubSequences(index+1, vec, arr, n, s, sum) == true){
        return true;
    };

    // In this call, we are not taking the element
    s -= arr[index];
    vec.pop_back();
    if(printSubSequences(index+1, vec, arr, n, s, sum) == true){
        return true;
    }
    return false;
}
int main(){
    int arr[] = {3, 1, 2};
    vector<int> vec;
    printSubSequences(0, vec, arr, sizeof(arr)/sizeof(int), 0, 3);
}