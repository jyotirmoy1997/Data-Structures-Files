#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int n;
    vector<pair<int, int>> *graph;
    Graph(int v)
    {
        n = v;
        graph = new vector<pair<int, int>>[n];
    }
    void addEdge(int u, int v, int w)
    {
        graph[u].push_back({v, w});
    }
    void show()
    {
        for(int i=0; i<n; i++)
        {
            cout << i << " - ";
            for(auto it:graph[i])
            {
                cout << "(" << it.first << "," << it.second << ")";
            }
            cout << endl;
        }
    }
    void dfs(int node, vector<int> &vis, stack<int> &trav){
        vis[node] = 1;
        for(auto v : graph[node]){
            if(!vis[v.first])
                dfs(v.first, vis, trav);
        }
        trav.push(node);
    }

    // Intuition -> First Find the Topological Sort, then For each node, compute the distance from source
    void minDistance(int source){
        stack<int> trav;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, vis, trav);
        }
        
        vector<int> dis(n, INT_MAX);
        dis[source] = 0;
        while(!trav.empty()){
            auto node = trav.top();
            trav.pop();
            int distance = dis[node];
            for(auto v : graph[node]){
                dis[v.first] = min(distance + v.second, dis[v.first]);
            }
        }
        for(int i=0; i<n; i++){
            cout << i << "->" << dis[i] << endl;
        }
    }

};
int main()
{
    int v = 7;
    Graph g(v);

    g.addEdge(0, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(4, 2, 1);
    g.addEdge(4, 0, 3);
    g.addEdge(6, 4, 2);
    g.addEdge(5, 4, 1);
    g.addEdge(6, 5, 3);

    g.show();
    cout << endl;
    g.minDistance(6);
}