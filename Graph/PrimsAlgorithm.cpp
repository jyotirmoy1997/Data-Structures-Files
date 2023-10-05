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
        for(int i=0; i<n; i++)
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
    void mstPrimsOptimal()
    {
        vector<int> vis(n, 0);
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}});
        vector<pair<int, int>> mst;
        int sum = 0;
        while(!pq.empty()){
            auto node = pq.top().second.first;
            auto parent = pq.top().second.second;
            auto edW = pq.top().first;

            pq.pop();

            if(vis[node] == 1)
                continue;

            if(parent >= 0){
                mst.push_back({parent, node});
                sum += edW;
            }
                
            vis[node] = 1;
            for(auto it : graph[node]){
                auto v = it.first;
                auto wt = it.second;
                if(!vis[v]){
                    pq.push({wt, {v, node}});
                }
            }
        }
        for(auto it : mst){
            cout << it.first << "-" << it.second << " ";
        }

        cout << endl << "Weight :: " << sum;
    }

};
int main()
{
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 4, 2);
    g.addEdge(4, 3, 1);
    g.addEdge(2, 3, 3);
    g.show();
    g.mstPrimsOptimal();
}