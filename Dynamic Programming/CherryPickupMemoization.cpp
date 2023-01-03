#include<bits/stdc++.h>
using namespace std;
int func(int i, int j1, int j2, int m, int n, vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp)
{
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;
    
    if(i == n-1){
        if(j1 == j2)
            return matrix[i][j1];
        
        else
            return matrix[i][j1] + matrix[i][j2];
    }

    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int res = INT_MIN;
    for(int d1=-1; d1<=1; d1++){
        for(int d2=-1; d2<=1; d2++){
            if(j1 == j2)
                res = max(res, matrix[i][j1] + func(i+1, j1+d1, j2+d2, m, n, matrix, dp));

            else
                res = max(res, matrix[i][j1] + matrix[i][j2] + func(i+1, j1+d1, j2+d2, m, n, matrix, dp));
        }
    }
    return dp[i][j1][j2] = res;
}
int main()
{
    vector<vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int m = matrix[0].size();
    int n = matrix.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

    cout << func(0, 0, m-1, m, n, matrix, dp);
}