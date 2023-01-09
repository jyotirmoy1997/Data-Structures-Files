/*We are given a target sum of ‘X’ and ‘N’ distinct 
numbers denoting the coin denominations. We need to 
tell the minimum number of coins required to reach the 
target sum. We can pick a coin denomination for any number of times we want.

Approach :: Either we don't take the coin, in that case we decrease the index and the target
stays the same. Or, we take the coin and add 1 to our answer and stay in the same index(As there is
an infinite supply of coins), and decrease the target by subtracting the value of that denomination
from that target.
*/

#include<bits/stdc++.h>
using namespace std;
int func(int index, int target, vector<int> &coins){
    if(index == 0){
        if(target % coins[index] == 0)
            return target/coins[index];
        return 1e9;
    }

    // When we are not taking a coin, the no. of denominations is 0.
    int notTake = 0 + func(index-1, target, coins);
    int take = 1e9;

    /*Very Important Thumb Rule ::
    Whenever there is an Infinite Supply of items or Multiple Use of items,
    In take case, THE INDEX WILL NOT CHANGE. As we can take only one denomination of a 
    particular coin, thus we take 1 as the take value and reduce the target amount */ 
    if(coins[index] <= target)
        take = 1 + func(index, target-coins[index], coins);
    
    return min(notTake, take);
}
int minCoins(vector<int> &coins, int target, int n){
    return func(n-1, target, coins);
}
int main(){
    vector<int> coins = {1, 2, 3};
    int target = 4;
    cout << minCoins(coins, target, coins.size());
}