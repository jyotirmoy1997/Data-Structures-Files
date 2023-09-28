#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFillBFS(vector<vector<int>>& image, int sr, int sc, int color){
    int n = image.size();
    int m = image[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int sourceColor = image[sr][sc];
    q.push({sr, sc});
    vis[sr][sc] = 1;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        image[r][c] = color;
        vis[r][c] = 1;
        q.pop();
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == sourceColor && vis[nrow][ncol] == 0){
                q.push({nrow, ncol});
            }
        }
    }
    return image;
}
vector<vector<int>> floodFillDFS(vector<vector<int>>& image, int sr, int sc, int color){
    int n = image.size();
    int m = image[0].size();

    stack<pair<int, int>> st;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int sourceColor = image[sr][sc];
    st.push({sr, sc});
    vis[sr][sc] = 1;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!st.empty()){
        int r = st.top().first;
        int c = st.top().second;
        image[r][c] = color;
        vis[r][c] = 1;
        st.pop();
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == sourceColor && vis[nrow][ncol] == 0){
                st.push({nrow, ncol});
            }
        }
    }
    return image;
}
int main(){
    vector<vector<int>> image = {{1,1,1},
                                {1,1,0},
                                {1,0,1}};
    
    vector<vector<int>> modifiedImage = floodFillDFS(image, 1, 1, 2);

    for(auto it : modifiedImage){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
}