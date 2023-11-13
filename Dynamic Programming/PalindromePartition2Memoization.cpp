#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int start, int end){
    while(start < end){
        if(s[start] != s[end])
            return false;

        start++;
        end--;
    }
    return true;
}
int func(int i, int n, string &s, vector<int> &dp){
    if(i == n)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;
    for(int j=i; j<n; j++){
        if(isPalindrome(s, i, j)){
            int cost = 1 + func(j+1, n, s, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}
int minCut(string s){
    int n = s.size();
    vector<int> dp(n, -1);
    return func(0, n, s, dp) - 1;
}
int main(){
    string s = "bababcbadcede";
    cout << minCut(s);
}