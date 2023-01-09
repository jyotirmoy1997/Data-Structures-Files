#include<bits/stdc++.h>
using namespace std;
int func(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0)
        return 1;
    
    if(index == 0)
        return (arr[0] == target) ? 1 : 0;

    if(dp[index][target] != -1)
        return dp[index][target];


    int notTake = func(index-1, target, arr, dp);
    int take = false;
    if(target >= arr[index])
        take = func(index-1, target-arr[index], arr, dp);

    return dp[index][target] = notTake + take;
}
int findWays(vector<int> &arr, int sum){
    vector<vector<int>> dp(arr.size(), vector<int> (sum+1, -1));
    return func(arr.size()-1, sum, arr, dp);
}
int countPartitions(vector<int> &arr, int sum){
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if(totalSum - sum < 0 || totalSum % 2)
        return 0;
    return findWays(arr, (totalSum - sum) / 2);
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    int sum = 4;
    cout << findWays(arr, sum);
}