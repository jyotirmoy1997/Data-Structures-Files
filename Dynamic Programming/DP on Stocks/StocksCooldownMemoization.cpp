#include<bits/stdc++.h>
using namespace std;
int func(int index, int canBuy, vector<int> &prices, vector<vector<int>> &dp){
    if(index >= prices.size())
        return 0;

    if(dp[index][canBuy] != -1)
        return dp[index][canBuy];
    
    int profit = 0;
    if(canBuy){
        int buy = -prices[index] + func(index+1, 0, prices, dp);
        int notBuy = 0 + func(index+1, 1, prices, dp);
        profit = max(buy, notBuy);
    }
    else{
        // Only the sell case has to changed
        int sell = prices[index] + func(index+2, 1, prices, dp);
        int notSell = 0 + func(index+1, 0, prices, dp);
        profit = max(sell, notSell);
    }
    return dp[index][canBuy] = profit;
}
int stocks(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return func(0, 1, prices, dp);
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << stocks(prices);
}