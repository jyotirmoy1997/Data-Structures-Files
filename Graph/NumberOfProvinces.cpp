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

    // BFS Traversal Function
    int numberOfProvinces()
    {
        vector<int> bfs;
        vector<int> vis(n, 0);

        int provinces = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for(auto it : graph[node])
                    {
                        if(!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }

};
int main()
{
    Graph g(8);
    
    // Component 1
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // Component 2
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    // Component 2
    g.addEdge(6, 7);

    g.show();

    cout << endl << "No. of Provinces :: " << g.numberOfProvinces();
}