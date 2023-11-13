#include<bits/stdc++.h>
using namespace std;
int maxSumAfterPartitioning(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> dp(n+1, 0);
    for(int index=n-1; index>=0; index--){
        int maxi = INT_MIN, maxAns = INT_MIN, len = 0;
        for(int i=index; i<min(n, index+k); i++){
            len++;
            maxi = max(maxi, arr[i]);
            int sum = len * maxi + dp[i+1];
            maxAns = max(sum, maxAns);
        }
        dp[index] = maxAns;
    }
    return dp[0]; 
}
int main(){
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    cout << maxSumAfterPartitioning(arr, 3);
}