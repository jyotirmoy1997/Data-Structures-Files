/* Given an N*M matrix filled with integer numbers, 
find the maximum sum that can be obtained from a path 
starting from any cell in the first row to any cell in the last row.

Approach 3 : 

Here, we will use tabulation to remove the recursion stack space

*/

#include<bits/stdc++.h>
using namespace std;
int fallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(m, vector<int> (n, 0));
    
    for(int j=0; j<n; j++){
        dp[0][j] = matrix[0][j]; 
    }
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            int leftDiagonal = matrix[i][j];
            int rightDiagonal = matrix[i][j];
            int top = matrix[i][j] + dp[i-1][j];
            
            leftDiagonal += (j-1 >= 0) ? dp[i-1][j-1] : -1e9;
            rightDiagonal += (j+1 < m) ? dp[i-1][j+1] : -1e9;

            dp[i][j] = max(top, max(leftDiagonal, rightDiagonal));
        }
    }
    
    int res = INT_MIN;

    for(int j=0; j<m; j++){
        res = max(res, dp[n-1][j]);
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