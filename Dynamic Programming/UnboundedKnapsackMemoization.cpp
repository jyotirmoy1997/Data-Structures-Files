/*A thief wants to rob a store. He is carrying a bag of capacity W. 
The store has ‘n’ items. Its weight is given by the ‘wt’ array and 
its value by the ‘val’ array. He can either include an item in its 
knapsack or exclude it but can’t partially have it as a fraction. 
We need to find the maximum value of items that the thief can steal.

Approach :: https://takeuforward.org/data-structure/unbounded-knapsack-dp-23/

Same as 0/1 Knapsack Problem. The only difference is that this problem is an
Infinite Supply Problem. So, in the take case, we stand at the same index rather than
changing it.

*/

#include<bits/stdc++.h>
using namespace std;
int func(int index, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> dp){
    if(index == 0){
        return ((int)W/wt[0])* val[0];
    }

    if(dp[index][W] != -1)
        return dp[index][W];


    int notTake = 0 + func(index-1, W, wt, val, dp);
    int take = INT_MIN;
    if(W >= wt[index])
        take = val[index] + func(index, W-wt[index], wt, val, dp);
    
    return dp[index][W] = max(take, notTake);
}
int knapSack(vector<int> &wt, vector<int> &val, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
    return func(n-1, maxWeight, wt, val, dp);
}
int main(){
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int maxWeight = 10;
    int n = wt.size();
    cout << knapSack(wt, val, n, maxWeight);
}