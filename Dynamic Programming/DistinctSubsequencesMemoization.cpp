#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, string &s1, string &s2,  vector<vector<int>> &dp){
    if(j < 0)
        return 1;
    if(i < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = func(i-1, j-1, s1, s2, dp) + func(i-1, j, s1, s2, dp);
    else
        return dp[i][j] = func(i-1, j, s1, s2, dp);
}
int distinctSubsequences(string s1, string s2){
    int i = s1.length()-1;
    int j = s2.length()-1;
    vector<vector<int>> dp(i+1, vector<int> (j+1, -1));
    return func(i, j, s1, s2, dp);
}
int main(){
    string s1 = "babgbag";
    string s2 = "bag";
    cout << distinctSubsequences(s1, s2);
}