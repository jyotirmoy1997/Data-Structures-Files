#include<bits/stdc++.h>
using namespace std;
void showMatrix(vector<vector<int>> &mat, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void spiralMatrix(vector<vector<int>> &mat, int n, int m){
    vector<int> res;
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;
    while(top <= bottom && left <= right){

        // Top Traversal
        for(int i=left; i<=right; i++)
            res.push_back(mat[top][i]);
        
        top++;

        // Right Traversal
        for(int i=top; i<=bottom; i++)
            res.push_back(mat[i][right]);
        
        right--;

        // Bottom Traversal
        if(top <= bottom){
            for(int i=right; i>= left; i--)
                res.push_back(mat[bottom][i]);
            bottom--;
        }
        
        // Left Traversal
        if(left <= right){
            for(int i=bottom; i>=top; i--)
                res.push_back(mat[i][left]);
            left++;
        }
        
    }
    for(auto it : res){
        cout << it << " ";
    }
}
int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int n = mat.size();
    int m = mat[0].size();
    spiralMatrix(mat, n, m);
    // showMatrix(mat, n);
    
}