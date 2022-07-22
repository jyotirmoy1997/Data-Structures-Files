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

    // BFS Traversal Function
    bool detectCycle()
    {
        // vector<int> bfs;
        vector<int> vis(n, 0);
        int i=0;
        if(!vis[i])
            {
                queue<pair<int, int>> q;
                q.push(make_pair(0, -1));
                vis[i] = 1;
                while(!q.empty())
                {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto it : graph[node])
                    {
                        if(!vis[it])
                        {
                            q.push(make_pair(it, node));
                            vis[it] = 1;
                        }
                        else if(parent != it)
                        {
                            return true;
                        }
                    }
                }
            }
        return false;

    }
};
int main()
{
    int v, e, u, x;
    cout << "Enter Number of Vertices :: ";
    cin >> v;
    Graph g(v+1);
    cout << "Enter Number of Edges :: ";
    cin >> e;
    for(int i=0; i<e; i++)
    {
        cout << "For Edge " << i + 1 << " Enter Incident Vertices :: \n";
        cout << "Enter Vertex 1 :: ";
        cin >> u;
        cout << "Enter Vertex 2 :: ";
        cin >> x;
        g.addEdge(u, x);
    }
    g.show();
    cout << g.detectCycle();
}