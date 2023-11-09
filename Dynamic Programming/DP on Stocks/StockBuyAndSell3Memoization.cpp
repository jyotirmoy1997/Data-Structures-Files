/* Given an array of the price of Stocks (index indicates days), 
we need to figure out what will be the maximum profit if the stock is
bought and sold a given number of times.

Note => We've to sell a stock before we can buy it again

Approach =>  We apply an extra variable called 'cap' which 
will keep track of how many transactions have been done.

1 transaction => 1 buy + 1 sell

*/

#include<bits/stdc++.h>
using namespace std;
int func(int index, int canBuy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
    if(cap == 0)
        return 0;
    if(index == prices.size())
        return 0;

    if(dp[index][canBuy][cap] != -1)
        return dp[index][canBuy][cap];

    int profit = 0;
    if(canBuy){
        int buy = -prices[index] + func(index+1, 0, cap, prices, dp);
        int notBuy = 0 + func(index+1, 1, cap, prices, dp);
        profit = max(buy, notBuy);
    }
    else{
        int sell = prices[index] + func(index+1, 1, cap-1, prices, dp);
        int notSell = 0 + func(index+1, 0, cap, prices, dp);
        profit = max(sell, notSell);
    }
    return dp[index][canBuy][cap] = profit;
}
int stocks(vector<int> &prices, int cap){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (cap+1, -1)));
    return func(0, true, cap, prices, dp);
}
int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int transcationLimit = 2;
    cout << stocks(prices, 2);
}