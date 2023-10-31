/* Very Important Thumb Rule : If there are counting problems, always return either
0 if case not satisfied, or return 1 if case satisfied. 

    In Sub subsequence pattern, we always either take or not take the element. So, there
    will be at max two sub-recursion calls.

    In the end, we return the summed up result
*/

#include<bits/stdc++.h>
using namespace std;
int countSubsequences(vector<int> &arr, int index, int sum, int k){
    // Base Case
    if(index == arr.size()){
        if(sum == k)
            return 1;
        
        return 0;
    }

    // Take Case
    sum += arr[index];
    int take = countSubsequences(arr, index + 1, sum, k);

    // Not Take Case
    sum -= arr[index];
    int notTake = countSubsequences(arr, index + 1, sum, k);

    return take + notTake;
}
int main(){
    vector<int> arr = {1, 2, 1};
    cout << countSubsequences(arr, 0, 0, 2);
}