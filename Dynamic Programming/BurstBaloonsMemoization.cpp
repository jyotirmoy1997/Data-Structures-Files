#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i > j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int maximum = INT_MIN;
    for(int k=i; k<=j; k++){
        int cost = arr[i-1] * arr[k] * arr[j+1] + func(i, k-1, arr, dp) + func(k+1, j, arr, dp);
        maximum = max(maximum, cost);
    }
    return dp[i][j] = maximum;
}
int burstBaloons(vector<int> &arr){
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return func(1, n, arr, dp);
}
int main(){
    vector<int> arr = {3, 1, 5, 8};
    cout << burstBaloons(arr);
}