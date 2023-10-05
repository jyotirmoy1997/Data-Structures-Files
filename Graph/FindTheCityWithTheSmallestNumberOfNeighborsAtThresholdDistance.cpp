#include<bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
    vector<vector<int>> vis(n, vector<int> (n, 1e9));
    for(auto it : edges){
        vis[it[0]][it[1]] = it[2];
        vis[it[1]][it[0]] = it[2];
        vis[it[0]][it[0]] = 0;
        vis[it[1]][it[1]] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                vis[j][k] = min(vis[j][k], vis[j][i] + vis[i][k]);
            }
        }
    }

    int city = -1, maxi = n+1;

    for(int j=0; j<n; j++){
        int count = 0;
        for(int k=0; k<n; k++){
           if(vis[j][k] <= distanceThreshold)
            count++;
        }
        if(count <= maxi){
            maxi = count;
            city = j;
        }
    }

    return city;   
}
int main(){

    vector<vector<int>> mat = {{0,1,3},
                               {1,2,1},
                               {1,3,4},
                               {2,3,1}};

    cout << findTheCity(4, mat, 4);
    // floydWarshall(mat);

    // for(auto it : mat){
    //     for(auto el : it){
    //         cout << el << " ";
    //     }
    //     cout << endl;
    // }
}