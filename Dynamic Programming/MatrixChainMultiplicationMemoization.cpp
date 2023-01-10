/* https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/

The array stores the dimension of n-1 different matrices.

Dim A => 10 x 20
Dim B => 20 x 30
Dim C => 30 x 40
Dim D => 40 x 50

The task is to minimize the number of scaler multiplication operations required.
For two given matrices A => ( m x n ) and B => (n x o), the number of scaler operations
will be m x n x o.

*/

#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i == j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    int minimum = INT_MAX;
    for(int k=i; k<j; k++){
        int steps = (arr[i-1] * arr[k] * arr[j]) + func(i, k, arr, dp) + func(k+1, j, arr, dp);
        minimum = min(steps, minimum);
    }
    return dp[i][j] = minimum;
}
int minimumOperations(vector<int> &arr, int n){
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return func(1, n-1, arr, dp);
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << minimumOperations(arr, arr.size());
}