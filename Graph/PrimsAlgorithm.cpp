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
        graph[v].push_back(make_pair(u, w));
    }
    void show()
    {
        for(int i; i<5; i++)
        {
            cout << "Vertex [" << i << "] is connected to :: \n";
            for(auto v : graph[i])
            {
                cout << v.first << " with weight :: " << v.second;
                cout << endl;
            }
            cout << endl;
        }
    }
    void mstPrimsBruteForce()
    {
        // Initialize the Parent Array
        int parent[n];

        // Initialize the Key Array
        int key[n];

        // Initialize the MST Set array
        bool mstSet[n];

        for(int i=0; i<n; i++)
        {
            key[i] = INT_MAX; // Initializing all elements of key as Infinity
            mstSet[i] = false;
            parent[i] = -1;
        }
        key[0] = 0;

        // A graph can have atmost n-1 edges so iterate over n-1 edges
        for(int count = 0; count<n-1; count++)
        {
            int minimum = INT_MAX, u;
            for(int v=0; v<n; v++)
            {
                if(mstSet[v] == false && key[v] < minimum)
                {
                    minimum = key[v];
                    u = v;
                }
                mstSet[u] = true;
            }
            mstSet[u] = true;
            for(auto it:graph[u])
            {
                int v = it.first;
                int w = it.second;
                if(mstSet[v] == false && w < key[v])
                {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
    }
    void mstPrimsOptimal()
    {
        // Initialize the Parent Array
        int parent[n];

        // Initialize the Key Array
        int key[n];

        // Initialize the MST Set array
        bool mstSet[n];

        for(int i=0; i<n; i++)
        {
            key[i] = INT_MAX; // Initializing all elements of key as Infinity
            mstSet[i] = false; // Initializing all elements of mstSet as False
        }
        key[0] = 0;
        parent[0] = -1;

        // Declaraing a Priority Queue

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        // A graph can have atmost n-1 edges so iterate over n-1 edges
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            mstSet[u] = true;
            for(auto it:graph[u])
            {
                int v = it.first;
                int w = it.second;
                if(mstSet[v] == false && w < key[v])
                {
                    parent[v] = u;
                    key[v] = w;
                    pq.push({key[v], v});
                    
                }
            }
        }
        for (int i = 1; i < n-1; i++) 
        {
            cout << parent[i] << " - " << i <<" \n";
        }
    }

};
int main()
{
    int v, e, u, x, wt;
    cout << "Enter Number of Vertices :: ";
    cin >> v;
    Graph g(v+1);
    cout << "Enter Number of Edges :: ";
    cin >> e;
    for(int i=0; i<e; i++)
    {
        cout << "For Edge " << i + 1 << " enter incident vertices and weight :: \n";
        cout << "Enter Vertex 1 :: ";
        cin >> u;
        cout << "Enter Vertex 2 :: ";
        cin >> x;
        cout << "Enter Weight :: ";
        cin >> wt;
        g.addEdge(u, x, wt);
    }
    g.show();
    g.mstPrimsOptimal();
}