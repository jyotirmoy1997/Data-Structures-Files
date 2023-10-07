/* Approach => Use the disjoint set data structure to figure out if a mail 
belongs to the same person or not */

#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent;
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
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n = accounts.size();
    unordered_map<string, int> mpp;
    DisjointSet ds(n);
    for(int i=0; i<n; i++){
        for(int j=1; j<accounts[i].size(); j++){
            auto mail = accounts[i][j];
            if(mpp.find(mail) == mpp.end()){
                mpp[mail] = i;
            }
            else{
                ds.unionByRank(i, mpp[mail]);
            }
        }
    }

    vector<string> mergedMail[n];
    for(auto it : mpp){
        string mail = it.first;
        int node = ds.findParent(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for(int i=0; i<n; i++){
        if(mergedMail[i].size() == 0)
            continue;

        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}};

    auto res = accountsMerge(accounts);

    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}