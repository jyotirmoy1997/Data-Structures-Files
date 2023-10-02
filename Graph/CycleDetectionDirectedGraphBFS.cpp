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
            cout << i << " - ";
            for(auto v : graph[i])
            {
                cout << v;
            }
            cout << endl;
        }
    }
    // This Approach uses Kahn's Algorithm. If the toposort has less than N nodes, 
    // it is guaranteed that there exists a cycle
    bool hasCycle()
    {
        vector<int> indegree(6, 0);
        queue<int> q;
        for(int i=0; i<6; i++)
        {
            for(auto it:graph[i])
                indegree[it]++;
        }
        for(int i=0; i<6; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            count++;
            for(auto it:graph[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return !(count == n);
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
    cout << g.hasCycle();
}