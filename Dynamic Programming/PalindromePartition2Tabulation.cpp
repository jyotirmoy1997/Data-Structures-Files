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
int minCut(string s){
    int n = s.size();
    vector<int> dp(n+1, 0);
    for(int i=n-1; i>=0; i--){
        int mini = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(s, i, j)){
                int cost = 1 + dp[j+1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    return dp[0] - 1;
}
int main(){
    string s = "bababcbadcede";
    cout << minCut(s);
}