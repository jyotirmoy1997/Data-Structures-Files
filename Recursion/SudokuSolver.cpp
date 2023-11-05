#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col, char ch){
    for(int i=0; i<9; i++){
        // Check all rows for the current character
        if(board[row][i] == ch)
            return false;

        // Check all columns for the current character
        if(board[i][col] == ch)
            return false;

        // Check the current 3 x 3 box for the current character
        if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == ch)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                for(char ch='1'; ch<='9'; ch++){
                    if(isValid(board, i, j, ch)){
                        board[i][j] = ch;
                        if(solve(board) == true)
                            return true;
                        
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board){
    solve(board);  
}
int main(){
    vector<vector<char>> board =  {{'.','9','.','.','.','2','.','.','.'},
                                   {'.','.','.','7','.','.','.','8','.'},
                                   {'.','5','4','.','3','.','7','.','.'},
                                   {'6','.','.','.','.','.','.','.','.'},
                                   {'.','.','.','.','.','1','.','.','2'},
                                   {'.','7','3','.','5','.','8','.','.'},
                                   {'9','.','.','.','.','.','4','.','.'},
                                   {'8','.','.','.','6','.','.','.','.'},
                                   {'.','4','6','.','.','5','.','1','.'}};
    
    solveSudoku(board);

    for(auto it : board){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
                                   
}