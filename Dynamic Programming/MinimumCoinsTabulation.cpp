#include<bits/stdc++.h>
using namespace std;
int minCoins(vector<int> &coins, int target, int n){
    vector<vector<int>> dp(n, vector<int> (target + 1, 1e9));

    for(int i=0; i<=target; i++){
        if(i % coins[0] == 0)
            dp[0][i] = i/coins[0];
    }
    
    for(int index=1; index<n; index++){
        for(int T=0; T<=target; T++){
            int notTake = 0 + dp[index-1][T];
            int take = 1e9;

            /*Very Important Thumb Rule ::
            Whenever there is an Infinite Supply of items or Multiple Use of items,
            In take case, THE INDEX WILL NOT CHANGE. As we can take only one denomination of a 
            particular coin, thus we take 1 as the take value and reduce the T amount */ 
            if(coins[index] <= T)
                take = 1 + dp[index][T-coins[index]];
                
            dp[index][T] = min(notTake, take);
        }
    }

    return dp[n-1][target];
}
int main(){
    vector<int> coins = {1, 2, 3};
    int target = 7;
    cout << minCoins(coins, target, coins.size());
}