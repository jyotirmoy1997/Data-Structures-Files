#include<bits/stdc++.h>
using namespace std;
int func(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0)
        return 1;
    
    if(index == 0)
        return (arr[0] == target) ? 1 : 0;

    if(dp[index][target] != -1)
        return dp[index][target];


    int notTake = func(index-1, target, arr, dp);
    int take = false;
    if(target >= arr[index])
        take = func(index-1, target-arr[index], arr, dp);

    return dp[index][target] = notTake + take;
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    int sum = 4;
    vector<vector<int>> dp(arr.size(), vector<int> (sum+1, -1));
    cout << func(arr.size()-1, sum, arr, dp);
}