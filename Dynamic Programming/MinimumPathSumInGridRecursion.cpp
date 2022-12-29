#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<vector<int>> &arr){
    if(i == 0 && j == 0)
        return arr[0][0];
    
    if(i < 0 || j < 0)
        return 1e9;

    int top = arr[i][j] + func(i-1, j, arr);
    int left = arr[i][j] + func(i, j-1, arr);

    return min(top, left);
}
int main(){
    vector<vector<int>> arr = {
        {10, 8, 2},
        {10, 5, 100},
        {1, 1, 2}
    };
    cout << func(2, 2, arr);
}