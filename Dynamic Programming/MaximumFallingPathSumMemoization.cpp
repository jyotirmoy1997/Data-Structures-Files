/* Given an N*M matrix filled with integer numbers, 
find the maximum sum that can be obtained from a path 
starting from any cell in the first row to any cell in the last row.

Approach 2 : 

Here, we will start from the last row and will come to the first row.
We will use Recursion to track all the paths. Then we will use memoization to 
reduce the complexity

*/

#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp){
    if(j < 0 || j >= n-1)
        return -1e9;
        
    if(i == 0)
        return matrix[0][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int top = matrix[i][j] + func(i-1, j, matrix, n, dp);
    int leftDiagonal = matrix[i][j] + func(i-1, j-1, matrix, n, dp);
    int rightDiagonal = matrix[i][j] + func(i-1, j+1, matrix, n, dp);

    return dp[i][j] = max(top, max(leftDiagonal, rightDiagonal));
}

int fallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(m, vector<int> (n, -1));

    int res = -1e9;
    for(int i=0; i<n; i++){
        res = max(res, func(n-1, i, matrix, m, dp));
    }
    return res;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };
    cout << fallingPathSum(matrix);
}