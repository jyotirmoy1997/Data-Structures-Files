#include<bits/stdc++.h>
using namespace std;

/*  Pascal's Triangle =>


Row 1:                      1
Row 2:                  1       1
Row 3:              1       2       1
Row 4:          1       3       3       1
Row 5:      1       4       6       4       1
Row 6:  1       5       10      10      5       1

*/

/*Variation 1 : Given Row and Column Number, find the corresponding element in Pascal's Triangle
Say Row = 5, Column = 3, Then The Element is 6 (Column Starts From 1)
Formula : nCr where n = Row-1, c = Column-1; */

int nCr(int n, int r){
    int res = 1;
    for(int i=0; i<r; i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}
int pascalTriangleElement(int row, int column){
    return nCr(row-1, column-1);
}

// Variation 2 : Print any nth row in Pascal's Triangle

vector<int> pascalTriangleRow(int row){
    int res = 1;
    vector<int> ans;
    ans.push_back(res);
    for(int i=1; i<row; i++){
        res *= (row-i);
        res /= i;
        ans.push_back(res);
    }
    return ans;
}

// Variation 3 : Print the Pascal's Triangle

vector<vector<int>> pascalTriangle(int rows){
    vector<vector<int>> res;
    for(int i=1; i<=rows; i++){
        res.push_back(pascalTriangleRow(i));
    }
    return res;
}

int main(){
    auto ans = pascalTriangle(6);
    for(auto it : ans){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
        
}