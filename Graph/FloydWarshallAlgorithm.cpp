#include<bits/stdc++.h>
using namespace std;
#define I 100000000
void floydWarshall(vector<vector<int>> &mat){
    int V = mat.size();
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
            }
        }
    }

    // For Negative Cycles, if the diagonal elements are less than 0, then
    // we can definitely say that there exists a negative cycle.
    for(int i=0; i<V; i++){
        if(mat[i][i] < 0)
            cout << "Negative Cycle Exists";
    }
}
int main(){

    vector<vector<int>> mat = {{0, 2, I, I},
                               {1, 0, 3, I},
                               {I, I, 0, I},
                               {3, 5, 4, 0}};

    floydWarshall(mat);

    for(auto it : mat){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
}