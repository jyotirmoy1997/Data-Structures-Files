#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc, vector<pair<int, int>> &vec){
    int n = grid.size();
    int m = grid[0].size();

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    stack<pair<int, int>> st;
    st.push({sr, sc});
    while(!st.empty()){
        int r = st.top().first;
        int c = st.top().second;
        vis[r][c] = 1;
        st.pop();
        for(int k=0; k<4; k++){
            int nrow = r + drow[k];
            int ncol = c + dcol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                st.push({nrow, ncol});
                vec.push_back({r-nrow, c-ncol});
            }
        }
    }
}
int numberOfIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> st;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int, int>> vec;
                dfs(grid, vis, i, j, vec);
                st.insert(vec);
            }
        }
    }
    return st.size();
}
int main(){
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};

    cout << numberOfIslands(grid);
}