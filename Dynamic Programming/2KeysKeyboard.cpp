#include<bits/stdc++.h>
using namespace std;
int rec(int count, int clipboard, int n, vector<vector<int>> &dp){
    if(count > n)
        return 1e9;

    if(count == n)
        return 0;

    if(dp[count][clipboard] != -1)
        return dp[count][clipboard];
    
    int paste = 1 + rec(count + clipboard, clipboard, n, dp);
    int copyAndPaste = 2 + rec(count * 2, count, n, dp);

    return dp[count][clipboard] = min(copyAndPaste, paste);
}
int minSteps(int n){
    if(n == 1)
        return 0;
    
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return 1 + rec(1, 1, n, dp);
}
int main(){
    cout << minSteps(3);
}