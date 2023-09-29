#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int sr, int sc){
    int n = grid.size();
    int m = grid[0].size();

    int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

    stack<pair<int, int>> st;
    st.push({sr, sc});

    cout << endl;
    while(!st.empty()){
        int r = st.top().first;
        int c = st.top().second;
        cout << r << "-" << c << " ";
        vis[r][c] = 1;
        st.pop();
        for(int k=0; k<8; k++){
            int nrow = r + drow[k];
            int ncol = c + dcol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                st.push({nrow, ncol});
            }
        }
    }
}
int numberOfIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int islands = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                bfs(grid, vis, i, j);
                islands++;
            }
        }
    }
    return islands;
}
int main(){
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 1, 0, 0},
                                {0, 0, 0, 1, 1}};

    cout << numberOfIslands(grid);
}