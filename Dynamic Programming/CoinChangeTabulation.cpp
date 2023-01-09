/*We are given an array Arr with N distinct coins and a target. 
We have an infinite supply of each coin denomination. 
We need to find the number of ways we sum up the coin values to give us the target.

Each coin can be used any number of times..

Approach :: Either we don't take the coin, in that case we decrease the index and the target
stays the same. Or, we take the coin and add 1 to our answer and stay in the same index(As there is
an infinite supply of coins), and decrease the target by subtracting the value of that denomination
from that target.

Note =>  This is slightly different from the Minimum Coins problem.
In the minimum coins problem, we had to count the minimum number of ways to
find the minimum no. of coins. In this case, We have to count all the possible ways 
to take the coin.


*/

#include<bits/stdc++.h>
using namespace std;
long countCoins(vector<int> &coins, int target, int n){
    vector<vector<long>> dp(n, vector<long> (target+1, 0));

    for(int i=0; i<=target; i++){
        if(i % coins[0] == 0)
            dp[0][i] = i / coins[0];
    }

    for(int index=1; index<n; index++){
        for(int T=0; T<=target; T++){
            long notTake = dp[index-1][target];
            long take = 0;

            /*Very Important Thumb Rule ::
            Whenever there is an Infinite Supply of items or Multiple Use of items,
            In take case, THE INDEX WILL NOT CHANGE. */ 
            if(coins[index] <= target)
                take = dp[index][target-coins[index]];
                
            dp[index][target] = notTake + take;

        }
    }

    return dp[n-1][target];
}
int main(){
    vector<int> coins = {1, 2, 3};
    int target = 4;
    cout << countCoins(coins, target, coins.size());
}