#include<bits/stdc++.h>
using namespace std;
int traingle(int i, int j, int n, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(i == n-1)
        return arr[i][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int down = arr[i][j] + traingle(i+1, j, n, arr, dp);
    int diagonal = arr[i][j] + traingle(i+1, j+1, n, arr, dp);

    return dp[i][j] = min(down, diagonal);
}
int main(){
    vector<vector<int>> arr = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), -1));
    cout << traingle(0, 0, arr.size(), arr, dp);
}