#include<bits/stdc++.h>
using namespace std;
class Graph{
private:
    bool dfs(int node, int parent, vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, graph))
                    return true;
            }
            else if(it != parent)
                return true;
        }
        return false;
    }
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
        for(int i; i<5; i++)
        {
            cout << "Vertex [" << i << "] is connected to :: ";
            for(auto v : graph[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // DFS Traversal Function
    bool detectCycle()
    {
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, graph))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(2, 3);
    g.show();
    cout << g.detectCycle();
}