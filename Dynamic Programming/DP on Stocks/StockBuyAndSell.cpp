/* Given an array of the price of Stocks (index indicates days), 
we need to figure out what will be the maximum profit if the stock is
bought and sold exactly once.

Note => We've to sell a stock before we can buy it again

*/


#include<bits/stdc++.h>
using namespace std;
int stocks(vector<int> &prices){
    int mini = prices[0];
    int maxProfit = 0;
    for(int i=1; i<prices.size(); i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << stocks(prices);
}