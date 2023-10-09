/*An Articulation Point is a node in a graph upon whose removal 
the graph is broken down into multiple components*/ 

#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent,  vector<int> adj[],
        vector<int> &vis, vector<int> &tin, vector<int> &low,
        vector<int> &mark, int &timer){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for(auto it : adj[node]){
        if(it != parent){
            if(vis[it] == 0){
                dfs(it, node, adj, vis, tin, low, mark, timer);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }

    // The starting point of a graph is always an articulation point if it has more than 1 child
    // Because, upon removal of this node, the graph will always break down into multiple components
    if(child > 1 && parent == -1){
        mark[node] = 1;
    }
}
vector<int> articulationPoints(int n, vector<vector<int>> &connections) {
    vector<int> adj[n];
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    vector<int> tin(n, 0);
    vector<int> low(n, 0);
    vector<int> mark(n, 0);
    vector<int> res;
    int timer = 1;
    dfs(0, -1, adj, vis, tin, low, mark, timer);
    for(int i=0; i<n; i++){
        if(mark[i] == 1)
            res.push_back(i);
    }
    return res;
}
int main(){
    vector<vector<int>> connections = {{0, 1},
                                       {0, 2},
                                       {0, 3},
                                       {2, 4},
                                       {2, 5},
                                       {4, 6},
                                       {5, 6}};

    auto res = articulationPoints(7, connections);
    for(auto it : res){
        cout << it << " ";
    }
}