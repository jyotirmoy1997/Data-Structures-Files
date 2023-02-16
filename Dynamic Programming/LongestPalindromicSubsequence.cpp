#include<bits/stdc++.h>
using namespace std;
void func(string s1, string s2, vector<vector<int>> &dp, int n, int m){
    

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
}
int longestPalindromicSubsequence(string s1){
    string s2 = string(s1.rbegin(), s1.rend());
    int n = s1.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    func(s1, s2, dp, n, n);
    stack<char> st;
    int i=n, j=n;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            st.push(s1[i-1]);
            i--;
            j--;
        }
        else{
            if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }    
    }
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        cout << it << "";
    }
    return dp[n][n];
}
int main(){
    string s1 = "bbabcbcab";
    cout << endl << longestPalindromicSubsequence(s1);

}