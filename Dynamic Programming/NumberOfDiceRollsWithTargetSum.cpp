#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7; 
int func(vector<vector<int>>& dp, int n, int k, int target) {
    if (target == 0 && n == 0) 
        return 1;
    if (n == 0 || target <= 0) 
        return 0;

    if (dp[n][target] != -1) 
        return dp[n][target] % mod;

    int ways = 0; 
    for (int i = 1; i <= k; i++)
        ways = (ways + func(dp, n - 1, k, target - i)) % mod;
    
    return dp[n][target] = ways % mod;
}
int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return func(dp, n, k, target);
}
int main(){
    cout << numRollsToTarget(2, 6, 7);
}