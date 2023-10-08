#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n){

            // Assign each node's initial rank to 0;
            size.resize(n+1, 1);
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
        void unionBySize(int u, int v){
            int parent_U = findParent(u);
            int parent_V = findParent(v);

            // If both u & v has same parent, then they belong to the same component
            if(parent_U == parent_V)
                return;

            // If u's size is lesser than v's size, then attach u to v
            if(size[parent_U] < size[parent_V]){
                parent[parent_U] = parent_V;
                size[parent_V] += size[parent_U];
            }
            else{
                parent[parent_V] = parent_U;
                size[parent_U] += size[parent_V];
            }
        }
};
bool isValid(int nrow, int ncol, int n, int m){
    return (nrow >= 0 && nrow < n && ncol >=0 && ncol < m);
}
int largestIsland(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    DisjointSet ds(m * n);

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(grid[row][col] == 1){
                int node = row * m + col;
                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1){
                        int newNode = nrow * m + ncol;
                        ds.unionBySize(newNode, node);
                    }
                }
            }
        }
    }

    int maxi = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(grid[row][col] == 0){
                set<int> st;
                int node = row * m + col;
                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1){
                        int newNodeParent = ds.findParent(nrow * m + ncol);
                        st.insert(newNodeParent);
                    }
                }
                int size = 0;
                for(auto it : st){
                    size += ds.size[it];
                }
                maxi = max(maxi, size + 1);
            }
        }
    }

    for(int i=0; i<n*m; i++){
        maxi = max(maxi, ds.size[ds.findParent(i)]);
    }
    return maxi;
}