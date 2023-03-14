#include<bits/stdc++.h>
using namespace std;
int numberLIS(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maximum = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && (1 + dp[j]) > dp[i]){
                dp[i] = 1 + dp[j];
                count[i] = count[j];
            }
            else if(arr[j] < arr[i] && (1 + dp[j]) == dp[i]){
                count[i] += count[j];
            }
        }
        maximum = max(maximum, dp[i]);
    }
    int nos =0;
    
    for(int i=0; i<=n-1; i++){
       if(dp[i]==maximum) 
            nos+=count[i];
    }
    
    return nos;
}
int main(){

}