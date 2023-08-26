#include<bits/stdc++.h>
using namespace std;
void setMatrixZerosBrute(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){

                // Mark Columns
                for(int k=0; k<n; k++)
                    mat[k][j] = -1;
                
                // Mark Rows
                for(int k=0; k<m; k++)
                    mat[i][k] = -1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
}  
void setMatrixZerosBetter(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> rows(n, 0);
    vector<int> columns(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){

                // Mark Columns
                rows[i] = 1;
                
                // Mark Rows
                columns[j] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(rows[i] == 1 || columns[j] == 1){
                mat[i][j] = 0;
            }
        }
    }


}
void setZeroesOptimal(vector<vector<int>>& matrix) {
    /*
    Approach: This approach uses the first row and first col as a coordinate system.

    "For" loop - flag1:
    We remember if first row had any native/original zeros, we need to do this because we will be 
    using this row and the first column as a coordinate system for elements within the matrix.

    "For" loop - flag2:
    Similar to first row, the first col will later be used as a coordinate system. We will edit 
    the values here and so we need to know if it originally has a zero in it.

    First iteration of matrix - To find original zeros
    Here we find the original zeros of the matrix and assign the first element that corresponds to its 
    row and col as zero. Remember the first row and col act as coordinates here, and we can change 
    them bcs we already know if they had original zeros when we computed the flags.

    We have now set-up our coordinate system!
    Second iteration of matrix - Using coordinates to set valid non-zero elements to zero
    Now if the first element of the elements row or column is zero, we should replace the element 
    with zero. This is where we use the altered first row and first col.

    Iterate over first row:
    Now if originally our first row had zeros, the entire row should be made zero. 
    Note: If this step was put above the previous step ("Second iteration of matrix") 
    the entire matrix would be zero. Think why?

    Iterate over first col:
    Now if originally our first col had zeros, the entire col should be made zero.*/
    
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag1 = false, flag2 = false;
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){
                flag1 = true;
            }
        }
        for(int j=0; j<m; j++){
            if(matrix[0][j] == 0){
                flag2 = true;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(flag1 == true){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
        if(flag2 == true){
            for(int j=0; j<m; j++){
                matrix[0][j] = 0;
            }
        }
    }
int main(){
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};
    int n = mat.size();
    int m = mat[0].size();
    setMatrixZerosBetter(mat);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}