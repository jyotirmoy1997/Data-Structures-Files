/* Approach => First Transpose and Then Reverse Each Row*/

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
void reverse(vector<vector<int>> &mat, int i, int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(mat[i][start], mat[i][end]);
        start++;
        end--;
    }
}
void transpose(vector<vector<int>> &mat, int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(j != i)
                swap(mat[i][j], mat[j][i]);
        }
    }
}
void rotateMatrix(vector<vector<int>> &mat, int n){
    transpose(mat, n);
    for(int i=0; i<n; i++){
        reverse(mat, i, n);
    }
}
int main(){
    vector<vector<int>> mat = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    int n = mat.size();
    rotateMatrix(mat, n);
    showMatrix(mat, n);
    
}