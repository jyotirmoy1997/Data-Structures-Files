#include<bits/stdc++.h>
using namespace std;
class Graph{
private:
    bool dfs(int node, int parent, vector<int> &vis, vector<int> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, graph))
                    return true;
            }
            else if(it != parent)
                return true;
        }
        return false;
    }
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
        for(int i=0; i<n; i++)
        {
            cout << "Vertex [" << i << "] is connected to :: ";
            for(auto v : graph[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    vector<int> minDistance(){
        vector<int> dis(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({0, 0});
        dis[0] = 0;
        while(!q.empty()){
            auto node = q.front().first;
            auto dist = q.front().second;
            int nextDist = dist + 1;
            q.pop();
            for(auto it : graph[node]){
                if(nextDist < dis[it]){
                    dis[it] = nextDist;
                    q.push({it, nextDist});
                }
            }
        }
        return dis;
    }
};
int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 6);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(6, 8);
    g.show();
    cout << endl;
    auto res = g.minDistance();
    for(int i=0; i<res.size(); i++){
        cout << i << "->" << res[i] << endl;
    }
}