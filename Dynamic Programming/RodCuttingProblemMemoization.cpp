#include<bits/stdc++.h>
using namespace std;
int func(int index, int N, vector<int> &price, vector<vector<int>> &dp){
    if(index == 0)
        return N * price[0];
    
    if(dp[index][N] != -1)
        return dp[index][N];

    int notTake = 0 + func(index-1, N, price, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if(rodLength <= N)
        take = price[index] + func(index, N-rodLength, price, dp);
    
    return dp[index][N] = max(take, notTake);
}
int cutRods(vector<int> &price, int N){
    vector<vector<int>> dp(N, vector<int> (N+1, -1));
    int n = N-1;
    return func(n, N, price, dp);
}
int main(){
    vector<int> price = {2, 5, 7, 8, 10};
    int N = price.size();
    cout << cutRods(price, N);
}