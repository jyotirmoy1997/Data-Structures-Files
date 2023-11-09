/* Given an array of the price of Stocks (index indicates days), 
we need to figure out what will be the maximum profit if the stock is
bought and sold infinite number of times.

Note => We've to sell a stock before we can buy it again. 
In this scenario, a transcation fee is added to each transaction (Buy + Sell)

*/

#include<bits/stdc++.h>
using namespace std;
int func(int index, bool canBuy, vector<int> &prices, int fee){
    if(index == prices.size())
        return 0;
    int profit = 0;
    if(canBuy){
        int buy = -prices[index] + func(index+1, false, prices, fee);
        int notBuy = 0 + func(index+1, true, prices, fee);
        profit = max(buy, notBuy);
    }
    else{
        // Transaction Fee is deducted after one transcation
        int sell = prices[index] - fee + func(index+1, true, prices, fee);
        int notSell = 0 + func(index+1, false, prices, fee);
        profit = max(sell, notSell);
    }
    return profit;
}
int stocks(vector<int> &prices){
    return func(0, true, prices, 2);
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << stocks(prices);
}