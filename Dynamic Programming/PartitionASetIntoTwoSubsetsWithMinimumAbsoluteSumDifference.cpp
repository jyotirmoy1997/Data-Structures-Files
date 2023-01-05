/* You are given an array containing N non-negative integers. 
Your task is to partition this array into two subsets such that 
the absolute difference between subset sums is minimum.

You just need to find the minimum absolute difference 
considering any valid division of the array elements.

1. Each element of the array should belong to exactly one of the subset.

2. Subsets need not be contiguous always. For example, for the array : {1,2,3}, 
some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 


Approach => 

Pre-requisite => Sub set sum equals to Target - Tabulation.

In the last row of the table, we can determine which targetSum is possible from (0 - targetSum).
Thus, after precomputing the total sum, we can easily calculate the min value.


*/

#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &arr, int n)
{
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int k = totalSum;
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
    int minimum = 1e9;
    for(int s1=0; s1<=totalSum/2; s1++){
        if(dp[n-1][s1] == true)
            minimum = min(minimum, abs((totalSum - s1) - s1));
    }
    return minimum;
    
}

int main(){
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    
}