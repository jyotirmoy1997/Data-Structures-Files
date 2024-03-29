#include<bits/stdc++.h>
using namespace std;
int minimumCostCut(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

    for(int i=c; i>= 1; i--){
        for(int j=1; j<=c; j++){
            if(i > j)
                continue;
            
            int minimum = INT_MAX;
            for(int index = i; index <= j; index++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                minimum = min(minimum, cost);
            }
           dp[i][j] = minimum;

        }
    }
    return dp[1][c];
}
int main(){
    vector<int> cuts = {3,5,1,4};
	int c = cuts.size();
	int n = 7;
	cout << minimumCostCut(n, c, cuts);
	return 0;
}