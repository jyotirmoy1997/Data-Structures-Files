#include<bits/stdc++.h>
using namespace std;
int func(string s1, string s2, int n, int m, vector<vector<int>> &dp){

    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    for(int j=0; j<=m; j++)
        dp[0][j] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else   
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}
void shortestCommonSuperSequence(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout << "Length :: " << (n + m - func(s1, s2, n, m, dp));
    int i = n, j = m;
    string s = "";
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            s += s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                s += s1[i-1];
                i--;
            }
            else{
                s += s2[j-1];
                j--;
            }
        }
    }
    while(i > 0){
        s += s1[i-1];
        i--;
    }
    while(j > 0){
        s += s2[j-1];
        j--;
    }

    reverse(s.begin(), s.end());
    cout << s;
}
int main(){
    string s1 = "abcde";
    string s2 = "bdgek";
    shortestCommonSuperSequence(s1, s2);
}