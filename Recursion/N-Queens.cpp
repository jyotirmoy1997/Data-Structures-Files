#include<bits/stdc++.h>
using namespace std;

// This is the brute force solve function
bool isSafe(int row, int col, vector<string> &board, int n){
    int duprow = row;
    int dupcol = col;

    // Upper Left Diagonal Direction
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q')
            return false;

        row--;
        col--;
    }

    // Left Direction
    row = duprow;
    col = dupcol;
    while(col >= 0){
        if(board[row][col] == 'Q')
            return false;

        col--;
    }

    // Lower Left Diagonal Direction
    row = duprow;
    col = dupcol;
    while(row < n && col >= 0){
        if(board[row][col] == 'Q')
            return false;

        row++;
        col--;
    }

    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row <n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}


// Optimal Approach => Uses Hashing
void solveOptimal(int col, vector<string> &board, 
                  vector<vector<string>> &ans, int n, 
                  vector<int> &left, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
    
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row <n; row++){
        if(left[row] == 0 && 
           lowerDiagonal[row+col] == 0 && 
           upperDiagonal[n - 1 + row-col] == 0){

            board[row][col] = 'Q';
            left[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n - 1 + row-col] = 1;

            solveOptimal(col + 1, board, ans, n, left, upperDiagonal, lowerDiagonal);

            board[row][col] = '.';
            left[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n - 1 + row-col] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    vector<int> left(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
    string s(n, '.');
    for(int i=0; i<n; i++)
        board[i] = s; 
    
    solveOptimal(0, board, ans, n, left, upperDiagonal, lowerDiagonal);
    return ans;
}
int main(){
    int n = 8;
    auto res = solveNQueens(n);
    for(auto it : res){
        for(auto el : it)
            cout << el << endl;

        cout << endl;
    }
}