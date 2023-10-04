#include<bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    // {dist, {row, col}}
    priority_queue<pair<int, pair<int, int>>, 
    vector<pair<int, pair<int, int>>>, 
    greater<pair<int, pair<int, int>>>> pq;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 1e9));
    pq.push({0, {0, 0}});
    vis[0][0] = 0;
    while(!pq.empty()){
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        int dist = pq.top().first;

        pq.pop();
        if(r == n-1 && c == m-1)
            return dist;

        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
                int newEffort = max(abs(heights[r][c] - heights[nrow][ncol]), dist);
                if(newEffort < vis[nrow][ncol]){
                    vis[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            } 
        }
    }
    return 0;

}
int main()
{
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << minimumEffortPath(heights);
}