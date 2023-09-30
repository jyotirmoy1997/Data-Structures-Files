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
        graph[v].push_back(u);
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
    bool dfs(int node, int color, vector<int> &vis){
        vis[node] = color;
        for(auto v : graph[node]){
            if(vis[v] == -1){
                if(dfs(v, !color, vis) == false)
                    return false;   
            }
            else if(vis[v] == color)
                return false;
        }
        return true;
    }
    bool isBipartite(){
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                 if(dfs(i, 0, vis) == false)
                    return false;   
            }
        }
        return true;
    }
};
int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(5, 8);
    g.addEdge(4, 8);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(6, 7);
    g.show();
    
    cout << g.isBipartite();
}