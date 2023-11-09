/* Given an array of the price of Stocks (index indicates days), 
we need to figure out what will be the maximum profit if the stock is
bought and sold infinite number of times.

Note => We've to sell a stock before we can buy it again
In this problem, you cannot buy a stock immedietly after you've 
sold it.

Approach => In the sell case, instead of moving the index to the next one,
i.e index+1, we will move the index to index+2

*/

#include<bits/stdc++.h>
using namespace std;
int func(int index, bool canBuy, vector<int> &prices){
    if(index >= prices.size())
        return 0;

    int profit = 0;
    if(canBuy){
        int buy = -prices[index] + func(index+1, false, prices);
        int notBuy = 0 + func(index+1, true, prices);
        profit = max(buy, notBuy);
    }
    else{
        // Only the sell case has to be modified
        int sell = prices[index] + func(index+2, true, prices);
        int notSell = 0 + func(index+1, false, prices);
        profit = max(sell, notSell);
    }
    return profit;
}
int stocks(vector<int> &prices){
    return func(0, true, prices);
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << stocks(prices);
}