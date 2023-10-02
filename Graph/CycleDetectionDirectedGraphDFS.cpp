#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int n;
    vector<int> *graph;
    Graph(int v)
    {
        n = v;
        graph = new vector<int>[n];
    }
    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
    }
    void show()
    {
        for(int i=0; i<n; i++)
        {
            cout << "Vertex [" << i << "] is connected to :: ";
            for(auto v : graph[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto v : graph[node]){
            if(vis[v] == 0){
                if(dfs(v, vis, pathVis) == true)
                    return true;   
            }
            else if(pathVis[v] == 1)
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool hasCycle(){
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                 if(dfs(i, vis, pathVis))
                    return true;   
            }
        }
        return false;
    }
};
int main()
{
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(6, 4);
    g.addEdge(4, 5);
    g.addEdge(7, 1);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(7, 9);
    g.show();
    cout << g.hasCycle();
}