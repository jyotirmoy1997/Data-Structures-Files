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
        graph[v].push_back({u, w});
    }
    void show()
    {
        for(int i=1; i<n; i++)
        {
            cout << i << " - ";
            for(auto it:graph[i])
            {
                cout << "(" << it.first << "," << it.second << ")";
            }
            cout << endl;
        }
    }
};
int main()
{
    int v = 5;
    Graph g(v);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 1);

    g.show();
}