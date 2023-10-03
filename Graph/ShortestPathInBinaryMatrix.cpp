#include<bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid){
    if(grid[0][0] == 1)
        return -1;
    
    int n = grid.size();
    vector<vector<int>> vis(n, vector<int> (n, INT_MAX));
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    vis[0][0] = 0;

    int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
    while(!q.empty()){
        auto r = q.front().first.first;
        auto c = q.front().first.second;
        auto dist = q.front().second;
        q.pop();
        if(r == n-1 && c == n-1)
            break;

        for(int i=0; i<8; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            int newDist = dist + 1;
            if(nrow >= 0 && nrow < n 
            && ncol >= 0 && ncol < n 
            && grid[nrow][ncol] == 0 
            && newDist < vis[nrow][ncol]){
                q.push({{nrow, ncol}, newDist});
                vis[nrow][ncol] = newDist;
            }
        }
    }
    return (vis[n-1][n-1] == INT_MAX) ? -1 : vis[n-1][n-1] + 1;
}
int main(){
    vector<vector<int>> grid = {{0,0,0},
                                {1,1,0},
                                {1,1,0}};
    
    cout << shortestPathBinaryMatrix(grid);
}