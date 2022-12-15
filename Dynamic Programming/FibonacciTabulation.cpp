/* Using Tabulation to compute the fibonacci number. 
Here, we are using a vector to store the results of the intermediately called functions.

Note => Here, we are starting from a bottom up approach

*/

#include<bits/stdc++.h>
using namespace std;
int fibo(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    vector<int> dp(6, -1);
    cout << fibo(3, dp);
}