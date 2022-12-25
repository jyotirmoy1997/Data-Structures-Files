#include<bits/stdc++.h>
using namespace std;
int func(int m, int n){
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for(int i=0; i<=m-1; i++){
        for(int j=0; j<=n-1; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            
            int bottom = (i > 0) ? dp[i-1][j] : 0;
            int right = (j > 0) ? dp[i][j-1] : 0;
            
            dp[i][j] = bottom + right;
        }
    }
    return dp[m-1][n-1];
}
int main(){
    cout << func(3, 3);
}