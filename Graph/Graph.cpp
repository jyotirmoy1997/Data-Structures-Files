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
}