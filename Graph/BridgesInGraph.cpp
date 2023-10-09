// This Goes by Critical Connections in a Network in Leetcode

#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent,  vector<int> adj[],
        vector<int> &vis, vector<int> &tin, vector<int> &low,
        vector<vector<int>> &bridges, int &timer){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it : adj[node]){
        if(it != parent){
            if(vis[it] == 0){
                dfs(it, node, adj, vis, tin, low, bridges, timer);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it, node});
                }
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
}
vector<vector<int>> bridgesInGraph(int n, vector<vector<int>> &connections) {
    vector<int> adj[n];
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    vector<int> tin(n, 0);
    vector<int> low(n, 0);
    vector<vector<int>> bridges;
    int timer = 1;
    dfs(0, -1, adj, vis, tin, low, bridges, timer);
    return bridges;
}
int main(){
    vector<vector<int>> connections = {{0, 1},
                                       {1, 2},
                                       {3, 2},
                                       {0, 3},
                                       {3, 4},
                                       {4, 5},
                                       {5, 6},
                                       {5, 8},
                                       {6, 7},
                                       {7, 8},
                                       {7, 9},
                                       {9, 10},
                                       {9, 11},
                                       {10, 11}};

    auto res = bridgesInGraph(12, connections);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}