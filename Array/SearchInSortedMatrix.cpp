// Hypothetically Flatten the array to figure out the row and col no. =>
// Formula for calculating Row and Col No. from Hypothetical Flattened Array
// Row = Val / m (m = col no.)
// Column = Val % m (m = col no.)

#include<bits/stdc++.h>
using namespace std;
bool binarySearchMatrix(vector<vector<int>> &mat, int x){
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = (n * m)-1;
    while(low <= high){
        int mid = (low + high)/2;

        
        int row = mid / m;
        int col = mid % m;
        if(mat[row][col] == x)
            return true;

        else if(mat[row][col] > x)
            high = mid - 1;
        
        else
            low = mid + 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << binarySearchMatrix(mat, 3);
}