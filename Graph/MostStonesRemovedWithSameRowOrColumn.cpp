/* Check striver's video : the formula is (n - number of components)*/

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
int removeStones(vector<vector<int>> &stones){
    int n = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for(auto it : stones){
        maxRow = max(maxRow, it[0]);
        maxRow = max(maxRow, it[1]);
    }

    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> mpp;
    for(auto it : stones){
        int nodeRow = it[0];
        int nodeCol = it[1] + maxCol + 1;
        ds.unionByRank(nodeRow, nodeCol);
        mpp[nodeRow] = 1;
        mpp[nodeCol] = 1;
    }
    int count = 0;
    for(auto it : mpp){
        if(ds.findParent(it.first) == it.first)
            count++;
    }
    return n - count;
}
int main(){
    vector<vector<int>> stones = {{0,0},
                                  {0,1},
                                  {1,0},
                                  {1,2},
                                  {2,1},
                                  {2,2}};

    cout << removeStones(stones);
}