#include<bits/stdc++.h>
using namespace std;
 int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> adj[n+1];
    for(auto it : times){
        adj[it[0]].push_back({it[1], it[2]});
    }
    for(int i=0; i<n; i++){
        auto it = adj[i];
        cout << i << "->";
        for(auto el : it){
            cout << el.first << "-" << el.second << " ";
        }
        cout << endl;
    }
    queue<pair<int, int>> q;
    vector<int> vis(n+1, INT_MAX);
    cout << endl;
    
    vis[k] = 0;
    for(int i=0; i<=n; i++){
       cout << vis[i] << " ";
    }
    q.push({k, 0});
    cout << endl;
    
    while(!q.empty()){
        auto it = q.front();
        int node = it.first;
        int dist = it.second;
        cout << node << " ";
        q.pop();
        for(auto v : adj[node]){
            int adjNode = v.first;
            int cost = v.second;
            if(dist + cost < vis[adjNode]){
                vis[adjNode] = dist + cost;
                q.push({adjNode, vis[adjNode]});
            }
        }
    }
    cout << "Reach";
    int maxi = vis[1];
    for(int i=2; i<=n; i++){
        maxi = max(maxi, vis[i]);
    }
    if(maxi == INT_MAX)
        return -1;
    return maxi;
    return 0;
}
int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << networkDelayTime(times, 4, 2);
}