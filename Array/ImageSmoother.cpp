#include<bits/stdc++.h>
using namespace std;
int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool isValid(int row, int col, int n, int m){
    return row >= 0 && row < n && col >= 0 && col < m;
}
int calculateAvg(int row, int col, int n, int m, vector<vector<int>>& img){
    int totalCells = 1, sum = img[row][col];
    for(int i=0; i<8; i++){
        int nRow = row + drow[i];
        int nCol = col + dcol[i];
        if(isValid(nRow, nCol, n, m)){
            sum += img[nRow][nCol];
            totalCells++;
        }
    }
    return sum / totalCells;
}
vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int n = img.size(), m = img[0].size();
    vector<vector<int>> res(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int avg = calculateAvg(i, j, n, m, img);
            res[i][j] = avg;
        }
    }
    return res;
}
int main(){
    vector<vector<int>> img = {{100,200,100},
                               {200,50,200},
                               {100,200,100}};
                            
    auto res = imageSmoother(img);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}