#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<int> onesRow(n, 0), onesCol(m, 0), zerosRow(n, 0), zerosCol(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 0){
                zerosRow[i]++;
                zerosCol[j]++;
            }
            else{
                onesRow[i]++;
                onesCol[j]++;
            }
        }
    }

    vector<vector<int>> diff(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
        }
    }
    return diff;
}
int main(){
    vector<vector<int>> grid = {{0,1,1},
                                {1,0,1},
                                {0,0,1}};

    auto res = onesMinusZeros(grid);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";

        cout << endl;
    }
}