#include<bits/stdc++.h>
using namespace std;
// Optimal Approach => Uses Hashing
int solveOptimal(int col, vector<string> &board, int n, 
                  vector<int> &left, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
    
    if(col == n){
        return 1;
    }

    int count = 0;
    for(int row = 0; row <n; row++){
        if(left[row] == 0 && 
           lowerDiagonal[row+col] == 0 && 
           upperDiagonal[n - 1 + row-col] == 0){

            board[row][col] = 'Q';
            left[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n - 1 + row-col] = 1;

            count += solveOptimal(col + 1, board, n, left, upperDiagonal, lowerDiagonal);

            board[row][col] = '.';
            left[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n - 1 + row-col] = 0;
        }
    }
    return count;
}
int solveNQueens(int n){
    vector<string> board(n);
    vector<int> left(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
    string s(n, '.');
    for(int i=0; i<n; i++)
        board[i] = s; 
    
    return solveOptimal(0, board, n, left, upperDiagonal, lowerDiagonal);
}
int main(){
    int n = 4;
    cout << solveNQueens(n);
}