#include<bits/stdc++.h>
using namespace std;
int numSpecial(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> rows(n, 0), cols(m, 0); 
    
    // Finding 1s in Rows and Columns
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) {
                rows[i]++;
                cols[j]++;
            }
        }
    }

    // Finding number of special 1s
    int totCount = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)
                totCount++;
        }
    }
    return totCount;
}
int main(){
    vector<vector<int>> mat = {{1,0,0},{0,1,0},{0,0,1}};
    cout << numSpecial(mat);
}