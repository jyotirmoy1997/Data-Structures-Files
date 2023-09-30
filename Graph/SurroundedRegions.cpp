#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &board, int sr, int sc, vector<vector<int>> &vis){
    int n = board.size();
    int m = board[0].size();
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
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                vis[nrow][ncol] = 1;
                st.push({nrow, ncol});
            }
        }
    }
}
void surroundedRegions(vector<vector<char>> &board){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));

    // First Row
    for(int i=0; i<m; i++){
        if(board[0][i] == 'O' && !vis[0][i])
            dfs(board, 0, i, vis);
    }

    // Last Row
    for(int i=0; i<m; i++){
        if(board[n-1][i] == 'O' && !vis[n-1][i])
            dfs(board, 0, i, vis);
    }

    // First Col
    for(int i=0; i<n; i++){
        if(board[i][0] == 'O' && !vis[i][0])
            dfs(board, 0, i, vis);
    }

    // Last Col
    for(int i=0; i<n; i++){
        if(board[i][m-1] == 'O' && !vis[i][m-1])
            dfs(board, 0, i, vis);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'O' && vis[i][j] == 1)
                board[i][j] = 'X';
        }
    }
}
int main(){
    vector<vector<char>> mat = {{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}};

    surroundedRegions(mat);
    for(auto it : mat){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}