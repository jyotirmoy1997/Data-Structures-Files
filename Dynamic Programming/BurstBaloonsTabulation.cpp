#include<bits/stdc++.h>
using namespace std;
int burstBaloons(vector<int> &arr){
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(i > j)
                continue;
            int maximum = INT_MIN;
            for(int k=i; k<=j; k++){
                int cost = arr[i-1] * arr[k] * arr[j+1] + dp[i][k-1] + dp[k+1][j];
                maximum = max(maximum, cost);
            }
            dp[i][j] = maximum;
        }
    }
    return dp[1][n];
}
int main(){
    vector<int> arr = {3, 1, 5, 8};
    cout << burstBaloons(arr);
}