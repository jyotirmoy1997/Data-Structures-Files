#include<bits/stdc++.h>
using namespace std;
int stocks(vector<int> &prices){
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);

    ahead[0] = ahead[1] = 0;

    
    for(int index=n-1; index>=0; index--){
        for(int canBuy = 0; canBuy <= 1; canBuy++){
            int profit;
            if(canBuy){
                int buy = -prices[index] + ahead[0];
                int notBuy = 0 + ahead[1];
                profit = max(buy, notBuy);
            }
            else{
                int sell = prices[index] + ahead[1];
                int notSell = 0 + ahead[0];
                profit = max(sell, notSell);
            }
            curr[canBuy] = profit;
        }
        ahead = curr;
    }
    return curr[1];
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << stocks(prices);
}