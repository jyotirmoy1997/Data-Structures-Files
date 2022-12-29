#include<bits/stdc++.h>
using namespace std;
int traingle(int n, vector<vector<int>> &arr){
    vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), -1));

    for(int j=0; j<n; j++)
        dp[n-1][j] = arr[n-1][j];

    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int down = arr[i][j] + dp[i+1][j];
            int digonal = arr[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, digonal);
        }
    }

    return dp[0][0];
}
int main(){
    vector<vector<int>> arr = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };
    cout << traingle(arr.size(), arr);
}