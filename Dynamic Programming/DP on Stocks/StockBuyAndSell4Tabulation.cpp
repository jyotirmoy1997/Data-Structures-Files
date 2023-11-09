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
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));
    for(int index=n-1; index>=0; index--){
        for(int canBuy=0; canBuy<2; canBuy++){
            for(int cap=1; cap<=k; cap++){
                int profit = 0;
                if(canBuy){
                    int buy = -prices[index] + dp[index+1][0][cap];
                    int notBuy = 0 + dp[index+1][1][cap];
                    profit = max(buy, notBuy);
                }
                else{
                    int sell = prices[index] + dp[index+1][1][cap-1];
                    int notSell = 0 + dp[index+1][0][cap];
                    profit = max(sell, notSell);
                }
                dp[index][canBuy][cap] = profit;
            }
        }
    }
    return dp[0][1][k];
}
int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int transcationLimit = 3;
    cout << maxProfit(transcationLimit, prices);
}