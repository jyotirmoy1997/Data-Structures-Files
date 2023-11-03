#include<bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, int n, int m){
    return row >=0 && row < n && col >=0 && col < m;
}
bool dfs(vector<vector<char>> &board, string word, int row, int col, 
         int n, int m, int index, vector<vector<int>> &vis){
    
    if(index == word.size()-1)
        return true;
    
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    for(int i=0; i<4; i++){
        int nextRow = row + drow[i];
        int nextCol = col + dcol[i];
        if(isValid(nextRow, nextCol, n, m) && 
           vis[nextRow][nextCol] == 0 && 
           board[nextRow][nextCol] == word[index + 1]){
            vis[nextRow][nextCol] = 1;
            if(dfs(board, word, nextRow, nextCol, n, m, index + 1, vis))
                return true;
            else
                vis[nextRow][nextCol] = 0;
           }
    }
    return false;
}
bool exist(vector<vector<char>> &board, string word){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                vis[i][j] = 1;
                if(dfs(board, word, i, j, n, m, 0, vis))
                    return true;
                
                vis[i][j] = 0;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    
    cout << exist(board, "SEE");
}