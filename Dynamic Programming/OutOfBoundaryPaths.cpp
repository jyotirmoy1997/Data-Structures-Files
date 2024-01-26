#include<bits/stdc++.h>
using namespace std;
vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};
int MOD = 1e9+7;
int func(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>> &dp){
    if(maxMove < 0)
        return 0;

    if(row < 0 || row >= m || col < 0 || col >= n)
        return 1;

    if(dp[row][col][maxMove] != -1)
        return dp[row][col][maxMove];
    
    int count = 0;
    for(int i=0; i<4; i++){
        int newRow = row + drow[i];
        int newCol = col + dcol[i];
        count = ((count % MOD) + (func(m, n, maxMove-1, newRow, newCol, dp)) % MOD) % MOD;
    }
    return dp[row][col][maxMove] = count % MOD;
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
    vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove+1, -1)));
    return func(m, n, maxMove, startRow, startColumn, dp);
}
int main(){

}