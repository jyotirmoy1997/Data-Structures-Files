#include<bits/stdc++.h>
using namespace std;
int func(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp){
    if(ind1 < 0 || ind2 < 0)
        return 0;

    if(dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    
    if(s1[ind1] == s2[ind2]){
        return dp[ind1][ind2] = 1 + func(s1, s2, ind1-1, ind2-1, dp);
    }
    
    return dp[ind1][ind2] = max(func(s1, s2, ind1-1, ind2, dp), func(s1, s2, ind1, ind2-1, dp));
}
int longestCommonSubsequence(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return func(s1, s2, n-1, m-1, dp);
}
int main(){
    string s1 = "acd";
    string s2 = "ced";
    cout << longestCommonSubsequence(s1, s2);
}