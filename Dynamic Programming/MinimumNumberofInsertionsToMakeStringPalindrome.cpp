#include<bits/stdc++.h>
using namespace std;
int func(string s1, string s2, vector<vector<int>> &dp, int n, int m){
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    for(int j=0; j<=m; j++)
        dp[0][j] = 0;  

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int longestPalindromicSubsequence(string s1, int n){
    string s2 = string(s1.rbegin(), s1.rend());
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    return func(s1, s2, dp, n, n);
}
int minInsertionsToMakePalindrome(string s1){
    int n = s1.size();
    return n - longestPalindromicSubsequence(s1, n);
}
int main(){
    string s1 = "abcaa";
    cout << minInsertionsToMakePalindrome(s1);
}