#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=0; i<=n; i++)
        dp[i][0] = i;
    
    for(int j=0; j<=m; j++)
        dp[0][j] = j;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
            {
                int insert = dp[i][j-1];
                int deletion = dp[i-1] [j];
                int replace = dp[i-1] [j-1];
                dp[i][j] =  1 + min(insert, min(replace, deletion));
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s1 = "horse";
    string s2 = "ros";
    cout << editDistance(s1, s2);
}