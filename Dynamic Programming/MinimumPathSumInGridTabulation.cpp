#include<bits/stdc++.h>
using namespace std;
int func(int m, int n, vector<vector<int>> &arr){
    vector<vector<int>> dp(m, vector<int> (n, -1));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int right = arr[i][j], bottom = arr[i][j];
            if(i == 0 && j == 0){
                dp[i][j] = arr[i][j];
            }
            else{
                right += (i > 0) ? dp[i-1][j] : 1e9;
                bottom += (j > 0) ? dp[i][j-1] : 1e9;
                dp[i][j] = min(right, bottom);
            }
        }
    }
    return dp[m-1][n-1];
}
int main(){
    vector<vector<int>> arr = {
        {10, 8, 2},
        {10, 5, 100},
        {1, 1, 2}
    };
    cout << func(3, 3, arr);
}