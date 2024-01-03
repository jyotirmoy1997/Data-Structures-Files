#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<vector<int>> &mat, int i, int m){
    if(mat[i][0] == 1)
        return 0;
    if(mat[i][m-1] == 0)
        return m;
    
    int low = 0, high = m-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(mat[i][mid] == 1 && mat[i][mid-1] == 0)
            return mid;
        else if(mat[i][mid] == 0)
            low = mid + 1;
        else if(mat[i][mid] == 1)
            high = mid - 1;
    }
    return -1;
}
int maximumOnes(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    int maxi = INT_MIN;
    
    for(int i=0; i<n; i++){
        int count = m - lowerBound(mat, i, m);
        maxi = max(maxi, count);
    }
    return maxi;
}
int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 1}, 
                               {0, 0, 1, 1}, 
                               {0, 0, 0, 1}, 
                               {0, 0, 0, 0}};
    cout << maximumOnes(mat);
}