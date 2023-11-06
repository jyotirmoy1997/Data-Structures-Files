/* Given an N*M matrix filled with integer numbers, 
find the maximum sum that can be obtained from a path 
starting from any cell in the first row to any cell in the last row.

Approach 1 : 

Here, we will start from the last row and will come to the first row.
We will use Recursion to track all the paths

*/


#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<vector<int>> &matrix, int n){
    if(j < 0 || j >= n-1)
        return -1e9;

    if(i == 0)
        return matrix[0][j];
    
    
    int top = matrix[i][j] + func(i-1, j, matrix, n);
    int leftDiagonal = matrix[i][j] + func(i-1, j-1, matrix, n);
    int rightDiagonal = matrix[i][j] + func(i-1, j+1, matrix, n);

    return max(top, max(leftDiagonal, rightDiagonal));
}

int fallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int res = -1e9;
    for(int i=0; i<m; i++){
        res = max(res, func(n-1, i, matrix, m));
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