/*
    Start from Top Right element and traverse in a diagonal fashion and check if the element 
    occurs or not.
    TC => O(n + m)

*/

#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int x){
    int n = mat.size(), m = mat[0].size();
    int row = 0, col = m-1;
    while(row < n && col >= 0){
        if(mat[row][col] == x)
            return true;
        
        else if(mat[row][col] < x)
            row++;
        
        else
            col--;
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1,4,7,11,15},
                               {2,5,8,12,19},
                               {3,6,9,16,22},
                               {10,13,14,17,24},
                               {18,21,23,26,30}};
    cout << searchMatrix(mat, 5);
}