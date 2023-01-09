#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (sum+1, 0));
    for(int i = 0; i < n; i++)
        dp[i][0] = 1;
    
    if(arr[0] <= sum)
        dp[0][arr[0]] = 1;


    for(int i=1; i<n; i++){
        for(int target=0; target<=sum; target++){
            int notTake = dp[i-1][target];
            int take = 0;
            if(target >= arr[i])
                    take = dp[i-1][target-arr[i]];

            dp[i][target] = notTake + take;
        }
    }
    return dp[n-1][sum];
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    int sum = 4;
    cout << func(arr, sum);
}