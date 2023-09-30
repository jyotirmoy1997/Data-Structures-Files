#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    vector<vector<int>> res(n, vector<int>(m, 0));
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int val = q.front().second;
        q.pop();
        res[r][c] = val;
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, val + 1});
            }
        }
    }
    return res;
}
int main(){
    vector<vector<int>> mat = {{0,0,0},
                               {0,1,0},
                               {1,2,1}};

    auto res = updateMatrix(mat);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}