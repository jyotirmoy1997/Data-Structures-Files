#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
    public:
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
bool isValid(int nrow, int ncol, int n, int m){
    return nrow >= 0 && nrow < n && ncol >=0 && ncol < m;
}
vector<int> numberOfIslands(int n, int m, vector<vector<int>> &queries){
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int count = 0;
    vector<int> ans;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    for(auto it : queries){
        int r = it[0];
        int c = it[1];
        if(vis[r][c] == 1){
            ans.push_back(count);
            continue;
        }
        vis[r][c] = 1;
        count++;
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(isValid(nrow, ncol, n, m)){
                if(vis[nrow][ncol] == 1){
                    int node = r * m + c;
                    int newNode = nrow * m + ncol;
                    if(ds.findParent(newNode) != ds.findParent(node)){
                        count--;
                        ds.unionByRank(newNode, node);
                    }
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}
int main(){
    vector<vector<int>> queries =  {{0, 0},
                                    {0, 0},
                                    {1, 1},
                                    {1, 0},
                                    {0, 1},
                                    {0, 3},
                                    {1, 3},
                                    {0, 4},
                                    {3, 2},
                                    {2, 2},
                                    {1, 2},
                                    {0, 2}};
    auto res = numberOfIslands(4, 5, queries);
    for(auto it : res){
        cout << it << " ";
    }
}