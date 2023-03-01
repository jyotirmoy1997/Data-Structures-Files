#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int index=n-1; index>=0; index--){
        for(int prev= index-1; prev>=-1; prev--){
            int take = 0;
            if(prev == -1 || arr[prev] < arr[index])
                take = 1 + dp[index+1][index+1];
            
            int notTake = 0 + dp[index+1][prev+1];

            dp[index][prev+1] = max(take, notTake);
        }
    }

    return dp[0][0];
}
int main(){
    vector<int> arr = {10, 9, 2, 3, 5, 7, 101, 18};
    cout << longestIncreasingSubsequence(arr);
}