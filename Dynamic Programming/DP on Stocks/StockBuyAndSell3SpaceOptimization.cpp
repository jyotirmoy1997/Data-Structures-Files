/* Rule of Space Optimization =>
   When there is like a next index (index + 1) & current index (index)
   Then we can always space optimize it.
   
   Replace dp[index], dp[index+1] with curr and next. 
   If the dimensions increase, then also increase the curr and next dimension by 1
   In the next iteration, replace next by curr.
    */

#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    for(int index=n-1; index>=0; index--){
        for(int canBuy=0; canBuy<2; canBuy++){
            for(int cap=1; cap<3; cap++){
                int profit = 0;
                if(canBuy){
                    int buy = -prices[index] + after[0][cap];
                    int notBuy = 0 + after[1][cap];
                    profit = max(buy, notBuy);
                }
                else{
                    int sell = prices[index] + after[1][cap-1];
                    int notSell = 0 + after[0][cap];
                    profit = max(sell, notSell);
                }
                curr[canBuy][cap] = profit;
            }
        }
        after = curr;
    }
    return after[1][2];
}
int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices);
}