#include<bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, int n, int m){
    return row >= 0 && row < n && col >=0 && col < m;
}
void rec(vector<vector<int>> &mat, vector<vector<int>> &vis, int row, int col, int n, int m, vector<string> &ans, string s){
    if(row == n-1 && col == m-1){
        ans.push_back(s);
        return;
    }

    int drow[] = {1, 0, 0, -1};
    int dcol[] = {0, -1, 1, 0};
    vector<char> directions = {'D', 'L', 'R', 'U'};

    for(int i=0; i<4; i++){
        int nextRow = drow[i] + row;
        int nextCol = dcol[i] + col;
        if(isValid(nextRow, nextCol, n, m) && vis[nextRow][nextCol] == 0 && mat[nextRow][nextCol] == 1){
            vis[nextRow][nextCol] = 1;
            rec(mat, vis, nextRow, nextCol, n, m, ans, s + directions[i]);
            vis[nextRow][nextCol] = 0;
        }
    }
}
vector<string> ratMaze(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    vis[0][0] = 1;
    vector<string> ans;
    string s = "";
    rec(mat, vis, 0, 0, n, m, ans, s);
    return ans;
}
int main(){
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1}, 
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    
    auto res = ratMaze(mat);
    for(auto it : res)
        cout << it << " ";
}