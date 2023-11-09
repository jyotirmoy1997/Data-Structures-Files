/* Given an array of the price of Stocks (index indicates days), 
we need to figure out what will be the maximum profit if the stock is
bought and sold exactly twice.

Note => We've to sell a stock before we can buy it again

Approach =>  We apply an extra variable called 'cap' which 
will keep track of how many transactions have been done.

1 transaction => 1 buy + 1 sell

*/

#include<bits/stdc++.h>
using namespace std;
int func(int index, bool canBuy, int cap, vector<int> &prices){
    if(cap == 0)
        return 0;
    if(index == prices.size())
        return 0;


    int profit = 0;
    if(canBuy){
        int buy = -prices[index] + func(index+1, false, cap, prices);
        int notBuy = 0 + func(index+1, true, cap, prices);
        profit = max(buy, notBuy);
    }
    else{
        int sell = prices[index] + func(index+1, true, cap-1, prices);
        int notSell = 0 + func(index+1, false, cap, prices);
        profit = max(sell, notSell);
    }
    return profit;
}
int stocks(vector<int> &prices, int cap){
    return func(0, true, cap, prices);
}
int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int transcationLimit = 2;
    cout << stocks(prices, 2);
}