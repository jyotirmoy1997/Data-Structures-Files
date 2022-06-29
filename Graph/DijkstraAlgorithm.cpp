#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int n;
    vector<pair<int, int>> *graph;
    public:
        Graph(int v)
        {
            n = v;
            graph = new vector<pair<int, int>>[n];
        }
        void addEdge(int u, int v, int w)
        {
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
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
        void trace(int v, int s, int prev[])
        {
            if(prev[v] == s)
            {
                cout << prev[v];
                return;
            }       
            cout << prev[v] << "->";
            trace(prev[v], s, prev);
        }
        void djikstra(int source, int destination)
        {
            int prev[n];
            int distance[n];
            for(int i=0; i<n; i++)
            {
                distance[i] = INT_MAX;
                prev[i] = -1;
            }
            distance[source] = 0;
            prev[source] = source;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(0, source));
            while(!pq.empty())
            {
                auto it = pq.top();
                // cout << it.first << " - " << it.second << endl;
                pq.pop();
                int u = it.second;
                for(auto adj : graph[u])
                {
                    int temp_distance = distance[u] + adj.second;
                    if(temp_distance < distance[adj.first])
                    {
                        distance[adj.first] = temp_distance;
                        prev[adj.first] = u;
                        pq.push(make_pair(distance[u] + adj.second, adj.first));
                    }
                }
            }

            cout << "Minimum distance from " << source << " to ::" << endl;
            for(int i=0; i<n; i++)
            {
                cout << i << " -> " << distance[i] << endl;
            }

            cout << "\nShortest route from destination to source :: " << destination << "->";
            trace(destination, source, prev);
        }
};
int main()
{
    int v = 5;
    // cout << "Enter number of vertices :: ";
    // cin >> v;
    Graph g(v);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 1);
    // g.show();
    g.djikstra(0, 4);
}