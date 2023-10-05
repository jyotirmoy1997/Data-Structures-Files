#include<bits/stdc++.h>
using namespace std;
vector<int> bellmanFordAlgorithm(int V, vector<vector<int>> &edges, int source){
    vector<int> dis(V, 1e9);
    dis[source] = 0;

    // Run Loop for N-1 Loop
    for(int i=0; i<V-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dis[u] != 1e9 && dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }

    // Additional Check for Negative Cycle. If negative cycle exists, then return an array with -1.
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(dis[u] != 1e9 && dis[u] + w < dis[v]){
            return {-1};
        }
    }

    return dis;
}
int main(){
    vector<vector<int>> edges = {{3, 2, 6}, 
                                 {5, 3, 1}, 
                                 {0, 1, 5}, 
                                 {1, 5, -3}, 
                                 {1, 2, -2}, 
                                 {3, 4, -2}, 
                                 {2, 4, 3}};

    auto res = bellmanFordAlgorithm(edges.size(), edges, 0);

    for(auto it : res){
        cout << it << " ";
    }
}