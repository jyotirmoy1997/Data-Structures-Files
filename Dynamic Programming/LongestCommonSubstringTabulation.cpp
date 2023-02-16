#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstring(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;

    int maximum = 0, ind1 = -1, ind2 = -1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                if(maximum < dp[i][j]){
                    maximum = dp[i][j];
                    ind1 = i;
                    ind2 = j;
                }
            }
        }
    }
    stack<char> st;
    while(dp[ind1][ind2] > 0){
        st.push(s1[ind1-1]);
        ind1--;
        ind2--;
    }
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        cout << it;
    }
    return maximum;
}
int main(){
    string s1 = "accdefghi";
    string s2 = "bxdefjgh";
    cout << endl << longestCommonSubstring(s1, s2);
}