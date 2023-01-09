#include<bits/stdc++.h>
using namespace std;
int func(int index, int target, vector<int> &coins, vector<vector<int>> &dp){
    if(index == 0){
        if(target % coins[index] == 0)
            return target/coins[index];
        return 1e9;
    }

    if(dp[index][target] != -1)
        return dp[index][target];


    // When we are not taking a coin, the no. of denominations is 0.
    int notTake = 0 + func(index-1, target, coins, dp);
    int take = INT_MAX;

    /*Very Important Thumb Rule ::
    Whenever there is an Infinite Supply of items or Multiple Use of items,
    In take case, THE INDEX WILL NOT CHANGE. As we can take only one denomination of a 
    particular coin, thus we take 1 as the take value and reduce the target amount */ 
    if(coins[index] <= target)
        take = 1 + func(index, target-coins[index], coins, dp);
    
    return dp[index][target] = min(notTake, take);
}
int minCoins(vector<int> &coins, int target, int n){
    vector<vector<int>> dp(n, vector<int> (target + 1, -1));
    return func(n-1, target, coins, dp);
}
int main(){
    vector<int> coins = {1, 2, 3};
    int target = 7;
    cout << minCoins(coins, target, coins.size());
}