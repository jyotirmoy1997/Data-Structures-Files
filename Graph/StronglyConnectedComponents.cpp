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
    void dfs(int node, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it])
                dfs(it, vis, st);
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> &vis, vector<int> revGraph[], vector<int> &trav){
        vis[node] = 1;
        for(auto it : revGraph[node]){
            if(!vis[it])
                dfs2(it, vis, revGraph, trav);
        }
        trav.push_back(node);
    }
    int stronglyConnectedComponents(){
        // Step 1 : Sort All the Edges according to the finishing Time - Do a DFS and Store it in the Stack
        vector<int> vis(n, 0);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, vis, st);
        }

        // Step 2 : Reverse The Graph
        vector<int> revGraph[n];
        for(int i=0; i<n; i++){
            vis[i] = 0;
            for(auto it : graph[i]){
                revGraph[it].push_back(i);
            }
        }

        // Step 3 : Again perform DFS and Count the number of Strongly Connected Components
        int count = 0;
        vector<vector<int>> res;
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            vector<int> trav;
            if(!vis[node]){
                count++;
                dfs2(node, vis, revGraph, trav);
            }
            if(trav.size() > 0)
                res.push_back(trav);
        }

        cout << "The Strongly Connected Components are :: " << endl;
        for(auto it : res){
            for(auto el : it)
                cout << el << " ";

            cout << endl;
        }

        cout << "Number of Strongly Connected Components :: ";

        return count;
    }
};
int main()
{
    int v = 7;
    Graph g(v+1);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 7);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    g.addEdge(6, 7);
    g.show();
    cout << g.stronglyConnectedComponents();
}