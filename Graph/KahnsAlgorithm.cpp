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
        for(int i; i<6; i++)
        {
            cout << i << " - ";
            for(auto v : graph[i])
            {
                cout << v;
            }
            cout << endl;
        }
    }
    void topologicalSortKahn()
    {
        vector<int> indegree(6, 0);
        queue<int> q;
        for(int i=0; i<6; i++)
        {
            for(auto it:graph[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0; i<6; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:graph[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        for(auto it:topo)
        {
            cout << it << " ";
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
    g.show();
    cout << endl;
    g.topologicalSortKahn();
}