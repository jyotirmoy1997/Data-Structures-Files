#include<bits/stdc++.h>
using namespace std;
bool func(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0)
        return true;
    
    if(index == 0)
        return (arr[0] == target);

    if(dp[index][target] != -1)
        return dp[index][target];


    bool notTake = func(index-1, target, arr, dp);
    bool take = false;
    if(target >= arr[index])
        take = func(index-1, target-arr[index], arr, dp);

    return dp[index][target] = (notTake || take);
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    vector<vector<int>> dp(arr.size(), vector<int> (k, -1));
    cout << func(arr.size()-1, k, arr, dp);
}