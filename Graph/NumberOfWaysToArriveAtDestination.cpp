#include<bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n];
    for(auto it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<int> dis(n, INT_MAX);
    vector<int> ways(n, 0);
    dis[0] = 0;
    ways[0] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto it = pq.top();
        auto dist = it.first;
        auto node = it.second;
        pq.pop();
        for(auto v : adj[node]){
            auto adjNode = v.first;
            auto cost = v.second;
            if(cost + dist < dis[adjNode]){
                dis[adjNode] = cost + dist;
                pq.push({cost + dist, adjNode});
                ways[adjNode] = ways[node];
            }
            else if(cost + dist == dis[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]);
            }
        }
    }
    return ways[n-1];
}
int main()
{
    vector<vector<int>> roads = {{0,6,7},
                                {0,1,2},
                                {1,2,3},
                                {1,3,3},
                                {6,3,3},
                                {3,5,1},
                                {6,5,1},
                                {2,5,1},
                                {0,4,5},
                                {4,6,2}};
    cout << countPaths(roads.size(), roads);
}