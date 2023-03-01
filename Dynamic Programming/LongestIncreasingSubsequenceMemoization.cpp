#include<bits/stdc++.h>
using namespace std;
int func(int index, int prev, vector<int> &arr, vector<vector<int>> &dp){
    if(index == arr.size()) 
        return 0;

    if(dp[index][prev+1] != -1)
        return dp[index][prev+1];


    // Take Case
    int take = INT_MIN;
    if(prev == -1 || arr[prev] < arr[index])
        take = 1 + func(index+1, index, arr, dp);
    
    int notTake = 0 + func(index+1, prev, arr, dp);

    return dp[index][prev+1] = max(take, notTake);
}
int longestIncreasingSubsequence(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return func(0, -1, arr, dp);
}
int main(){
    vector<int> arr = {10, 9, 2, 3, 5, 7, 101, 18};
    cout << longestIncreasingSubsequence(arr);
}