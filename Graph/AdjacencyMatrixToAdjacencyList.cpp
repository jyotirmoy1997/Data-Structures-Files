#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> mat = {{1,1,0},
                               {1,1,0},
                               {0,0,1}};

    int n = mat.size();
    vector<int> adj[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1 && i != j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << "Vertex [" << i << "] is connected to :: ";
        for(auto v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}