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
int main(){
    vector<int> arr = {1, 2, 3, 4};
    int k = 10;
    cout << func(arr, k, arr.size());
}