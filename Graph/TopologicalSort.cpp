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
    void dfs(int v, stack<int> &st, vector<int> &vis)
    {
        vis[v] = 1;
        for(auto it: graph[v])
        {
            if(!vis[it])
            {
                dfs(it, st, vis);
            }
        }
        st.push(v);
    }
    void topologicalSort()
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
        while(!trav.empty())
        {
            int v = trav.top();
            cout << v << " ";
            trav.pop();
        }
    }
    void show()
    {
        for(int i; i<5; i++)
        {
            cout << i << " - ";
            for(auto v : graph[i])
            {
                cout << v;
            }
            cout << endl;
        }
    }
};
int main()
{
    int v = 5;
    Graph g(v+1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    // g.show();
    g.topologicalSort();
}