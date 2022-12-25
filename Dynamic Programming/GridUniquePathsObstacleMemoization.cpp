#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(i == 0 && j == 0)
        return 1;
    
    if(i < 0 || j < 0 || (arr[i][j] == -1 && i >= 0 && j >= 0))
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int up = func(i-1, j, arr, dp);
    int left = func(i, j-1, arr, dp);

    return dp[i][j] = up + left;
}
int main(){
    vector<vector<int>> arr = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    vector<vector<int>> dp(3, vector<int> (3, -1));
    cout << func(2, 2, arr, dp);
}