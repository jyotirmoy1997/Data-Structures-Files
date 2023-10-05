#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n){

            // Assign each node's initial rank to 0;
            rank.resize(n+1, 0);
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
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}