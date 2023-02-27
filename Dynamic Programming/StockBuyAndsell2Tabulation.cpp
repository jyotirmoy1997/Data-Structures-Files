#include<bits/stdc++.h>
using namespace std;
int stocks(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, -1));

    dp[n][0] = dp[n][1] = 0;

    
    for(int index=n-1; index>=0; index--){
        for(int canBuy = 0; canBuy <= 1; canBuy++){
            int profit;
            if(canBuy){
                int buy = -prices[index] + dp[index+1][0];
                int notBuy = 0 + dp[index+1][1];
                profit = max(buy, notBuy);
            }
            else{
                int sell = prices[index] + dp[index+1][1];
                int notSell = 0 + dp[index+1][0];
                profit = max(sell, notSell);
            }
            dp[index][canBuy] = profit;
        }
    }
    return dp[0][1];
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << stocks(prices);
}