#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    if(i < 0)
        return j+1;
    
    if(j < 0)
        return i+1;

    if(dp[i][j] != -1)
        return dp[i][j];

    // Matching Logic. We won't return anything and will move to the next step
    if(s1[i] == s2[j])
        return dp[i][j] = 0 + func(i-1, j-1, s1, s2, dp);
    
    // Not Matching Logic. In this case, we will perform three operations.

    // Hypothetical Insertion, will move the latter index by 1
    int insert = func(i, j-1, s1, s2, dp);

    // Hypothetical Deletion, will move the previous index by 1
    int deletion = func(i-1, j, s1, s2, dp);
    
    // Hypothetical Replacing, will move both index by 1
    int replace = func(i-1, j-1, s1, s2, dp);

    return dp[i][j] =  1 + min(insert, min(replace, deletion));

}
int editDistance(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return func(n-1, m-1, s1, s2, dp);
}
int main(){
    string s1 = "horse";
    string s2 = "ros";
    cout << editDistance(s1, s2);
}