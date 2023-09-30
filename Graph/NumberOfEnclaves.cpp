#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, int sr, int sc, vector<vector<int>> &vis){
    int n = grid.size();
    int m = grid[0].size();
    stack<pair<int, int>> st;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    st.push({sr, sc});
    while(!st.empty()){
        int r = st.top().first;
        int c = st.top().second;
        st.pop();
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                st.push({nrow, ncol});
            }
        }
    }
}
int noOfEnclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));

    // First Row
    for(int i=0; i<m; i++){
        if(grid[0][i] == 1 && !vis[0][i])
            dfs(grid, 0, i, vis);
    }

    // Last Row
    for(int i=0; i<m; i++){
        if(grid[n-1][i] == 1 && !vis[n-1][i])
            dfs(grid, n-1, i, vis);
    }

    // First Col
    for(int i=0; i<n; i++){
        if(grid[i][0] == 1 && !vis[i][0])
            dfs(grid, i, 0, vis);
    }

    // Last Col
    for(int i=0; i<n; i++){
        if(grid[i][m-1] == 1 && !vis[i][m-1])
            dfs(grid, i, m-1, vis);
    }

    int enclaves = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && vis[i][j] == 0)
                enclaves++;
        }
    }
    return enclaves;
}
int main(){
    vector<vector<int>> mat = {{0,0,0,0},
                               {1,0,1,0},
                               {0,1,1,0},
                               {0,0,0,0}};

    int enclaves = noOfEnclaves(mat);
    cout << noOfEnclaves(mat);
    // for(auto it : mat){
    //     for(auto el : it)
    //         cout << el << " ";
        
    //     cout << endl;
    // }
}