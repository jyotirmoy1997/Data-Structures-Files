/*
    Approach => Select the range from 1 to 10^9.
    Apply Binary Search on this range
    Find the Mid.
    Find out how many elements are smaller than equal to this mid in the entire matrix(use Upperbound)
    if count <= (n x m) / 2 => Shift Up
    else   => Shift Down
*/

#include<bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &arr, int x){
    int low = 0, high = arr.size() - 1, ans = arr.size();
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid -1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int median(vector<vector<int>> &mat){
    int low = 1;
    int high = 1e9;
    int n = mat.size();
    int m = mat[0].size();
    while(low <= high){
        int mid = (low + high)/2;
        int count = 0;
        for(int i=0; i<n; i++)
            count += upperBound(mat[i], mid);

        if(count <= (n * m)/2)
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    vector<vector<int>> mat = {{1, 3, 8},
                               {2, 3, 4},
                               {1, 2, 5}};
    cout << median(mat);
}