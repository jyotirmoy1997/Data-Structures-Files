/*  Given an array 'ARR' of 'N' positive integers. 
The task is to find if we can partition the given array into 
two subsets such that the sum of elements in both subsets is equal

For example, let’s say the given array is [2, 3, 3, 3, 4, 5], 
then the array can be partitioned as [2, 3, 5], and [3, 3, 4] 
with equal sum 10.

Pre-requisite => Subset Sum Equals to Target

Approach =>

Calculate the total Sum. Divide it into two parts. If the sum is odd then
no partition is possible thus return false. If it is even, then call the 
utility function with sum/2. If there exists a sub sequence that matches sum/2,
then we return true, else return false


*/

#include<bits/stdc++.h>
using namespace std;
bool func(vector<int> &arr, int k, int n)
{
    vector<vector<bool>> dp(n, vector<bool> (k+1, false));

    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }

    if(arr[0] <= k)
        dp[0][arr[0]] = true;


    for(int index=1; index<n; index++){
        for(int target = 1; target<=k; target++){
            bool notTake = dp[index-1][target];
            bool take = false;
            if(target >= arr[index])
                take = dp[index-1][target-arr[index]];

            dp[index][target] = (notTake || take);
        }
    }
    return dp[n-1][k];
}

bool canPartition(vector<int> &arr, int n){
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if(totalSum % 2)
        return false;
    
    return func(arr, totalSum/2, n);
}

int main(){
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    cout << canPartition(arr, arr.size());
}