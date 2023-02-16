#include<bits/stdc++.h>
using namespace std;
int cutRods(vector<int> &price, int N){
    vector<vector<int>> dp(N, vector<int> (N+1, 0));

    for(int rL=0; rL<=N; rL++)
        dp[0][rL] = rL * price[0];
    
    for(int index=1; index<N; index++){
        for(int rLength=0; rLength<=N; rLength++){
            int notTake = 0 + dp[index-1][rLength];
            int take = INT_MIN;
            int rodLength = index + 1;
            if(rodLength <= rLength)
                take = price[index] + dp[index][rLength-rodLength];

            dp[index][rLength] = max(take, notTake);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<=N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[N-1][N];
}
int main(){
    vector<int> price = {2, 5, 7, 8, 10};
    int N = price.size();
    cout << endl << cutRods(price, N);
}