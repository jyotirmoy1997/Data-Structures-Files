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
        graph[u].push_back(make_pair(v, w));
    }
    void dfs(int v, stack<int> &st, vector<int> &vis)
    {
        vis[v] = 1;
        for(auto it: graph[v])
        {
            if(!vis[it.first])
            {
                dfs(it.first, st, vis);
            }
        }
        st.push(v);
    }
    void shortestPath()
    {
        vector<int> vis(n, 0);
        stack<int> trav;
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, trav, vis);
            }
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        while(!trav.empty())
        {
            int v = trav.top();
            // cout << v << " ";
            trav.pop();
            if(dist[v] != INT_MAX)
            {
                for(auto it: graph[v])
                {
                    int temp_distance = dist[v] + it.second;
                    if(temp_distance < dist[it.first])
                    {
                        dist[it.first] = temp_distance;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            cout << i << " - " << dist[i] << endl;
        }
    }
    // void show()
    // {
    //     for(int i; i<5; i++)
    //     {
    //         cout << i << " - ";
    //         for(auto v : graph[i])
    //         {
    //             cout << v;
    //         }
    //         cout << endl;
    //     }
    // }
};
int main()
{
    int v = 5;
    Graph g(v+1);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(5, 3, 1);
    g.addEdge(2, 3, 6);
    // g.show();
    g.shortestPath();
}