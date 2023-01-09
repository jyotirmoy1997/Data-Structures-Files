/*A thief wants to rob a store. He is carrying a bag of capacity W. 
The store has ‘n’ items. Its weight is given by the ‘wt’ array and 
its value by the ‘val’ array. He can either include an item in its 
knapsack or exclude it but can’t partially have it as a fraction. 
We need to find the maximum value of items that the thief can steal.

Approach :: https://takeuforward.org/data-structure/0-1-knapsack-dp-19/

*/

#include<bits/stdc++.h>
using namespace std;
int knapSack(vector<int> &wt, vector<int> &val, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

    for(int i=wt[0]; i<=maxWeight; i++)
        dp[0][i] = val[0];

    for(int index=1; index<n; index++){
        for(int W=0; W<=maxWeight; W++){
            int notTake = 0 + dp[index-1][W];
            int take = INT_MIN;
            if(W >= wt[index])
                take = val[index] + dp[index-1][W-wt[index]];
            dp[index][W] = max(take, notTake);
        }
    }

    return dp[n-1][maxWeight];
}
int main(){
    vector<int> wt = {3, 4, 5};
    vector<int> val = {30, 50, 60};
    int maxWeight = 8;
    int n = wt.size();
    cout << knapSack(wt, val, n, maxWeight);
}