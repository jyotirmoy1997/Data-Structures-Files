#include<bits/stdc++.h>
using namespace std;
bool func(int i, int j, string s1, string s2,  vector<vector<bool>> &dp){
    if(i < 0 && j < 0)
        return true;
    
    if(i < 0 && j >= 0)
        return false;
    
    if(i >= 0 && j < 0){
        for(int ind = 0; ind <= i; ind++){
            if(s1[ind] != '*')
                return false;
        }
        return true;
    }

    if(dp[i][j] != false)
        return dp[i][j];

    if(s1[i] == s2[j] || s1[i] == '?')
        return dp[i][j] = func(i-1, j-1, s1, s2, dp);

    if(s1[i] == '*')
        return dp[i][j] = func(i-1, j, s1, s2, dp) || func(i, j-1, s1, s2, dp);
        
    return dp[i][j] = false;
}
bool wildCardMatch(string s1, string s2){
    int n = s1.length() - 1;
    int m = s2.length() - 1;
    vector<vector<bool>> dp(n, vector<bool> (m, false));
    return func(n-1, m-1, s1, s2, dp); 
}
int main(){
    string s1 = "ab*de";
    string s2 = "abcfgde";
    cout << wildCardMatch(s1, s2);
}