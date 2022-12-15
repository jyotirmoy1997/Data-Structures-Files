/* Using Memoization to compute the fibonacci number. 
Here, we are using a vector to store the results of the intermediately called functions*/

#include<bits/stdc++.h>
using namespace std;
int fibo(int n, vector<int> &dp){
    if(n == 1)
        return 1;
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}
int main(){
    vector<int> dp(6, -1);
    cout << fibo(3, dp);
}