#include<bits/stdc++.h>
using namespace std;
int func(int n, vector<int> &dp){
    if(n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int mini = 1e9;
    for(int i=1; i*i<=n; i++)
        mini = min(mini, func(n-i*i, dp));
    
    return dp[n] = mini + 1;
}
int numSquares(int n){
    vector<int> dp(n+1, -1);
    return func(n, dp); 
}
int main(){
    cout << numSquares(12);
}