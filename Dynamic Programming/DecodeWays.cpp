#include<bits/stdc++.h>
using namespace std;
int func(string &s, int index, int n, vector<int> &dp){
    if(s[index] == '0')
        return 0;

    if(index == n)
        return 1;

    if(dp[index] != -1)
        return dp[index];
    
    // Append
    int takeOne = func(s, index+1, n, dp);

    // Add New
    int takeTwo = 0;
    if(index + 1 < s.length() && stoi(s.substr(index, 2)) <= 26)
        takeTwo = func(s, index+2, n, dp);

    return dp[index] = takeOne + takeTwo;
}
int numDecodings(string s){
    int n = s.length();
    vector<int> dp(n, -1);
    return func(s, 0, n, dp);
}
int main(){
    string s = "226";
    cout << numDecodings(s);
}