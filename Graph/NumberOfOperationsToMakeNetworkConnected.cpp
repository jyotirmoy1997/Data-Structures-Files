/*The Idea is to connect the graph using Disjoint Set. Now, while connecting we check whether
two nodes belong to the same component or not. If they belong to the same component, then we do not 
require to add them, instead, this will be an extra edge. This extra edge may be used later to connect
the different components of the graph. Now, if the graph has n components, we require n-1 components
at minimum to connect the graph. If the extra edges are greater than n-1, then we can definitely say that 
we can make the graph connected. */ 

#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
        vector<int> rank, parent;
        DisjointSet(int n){


            // Assign each node's initial rank to 0;
            rank.resize(n+1, 0);
            parent.resize(n+1);

            // Assign each node as its own parent
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }
        int findParent(int u){
            // Base case : If u has u itself as parent, then we can say we have reached the root node
            if(u == parent[u])
                return u;
            
            // Path compression
            return parent[u] = findParent(parent[u]);
        }
        void unionByRank(int u, int v){
            int parent_U = findParent(u);
            int parent_V = findParent(v);

            // If both u & v has same parent, then they belong to the same component
            if(parent_U == parent_V)
                return;

            // If u's rank is lesser than v's rank, then attach u to v
            if(rank[parent_U] < rank[parent_V]){
                parent[parent_U] = parent_V;
            }
            // If v's rank is lesser than u's rank, then attach v to u
            else if(rank[parent_U] > rank[parent_V]){
                parent[parent_V] = parent_U;
            }
            // If both has same rank, then attach v to u, increment the rank of u by 1
            else{
                parent[parent_V] = parent_U;
                rank[parent_U]++;
            }
        }
};
int makeConnected(int n, vector<vector<int>> &connections) {
    DisjointSet ds(n);
    int extraEdges = 0;

    for(auto it : connections){
        int u = it[0];
        int v = it[1];

        if(ds.findParent(u) != ds.findParent(v)){
            ds.unionByRank(u, v);
        }
        else{
            extraEdges++;
        }
    }

    // Count the number of components
    int components = 0;
    for(int i=0; i<n; i++){
        if(ds.parent[i] == i){
            components++;
        }

    }
    return (extraEdges >= components - 1) ? components - 1 : -1;
}
int main(){
    vector<vector<int>> connections = {{0,1},
                                       {0,2},
                                       {1,2}};

    cout << makeConnected(4, connections);
}