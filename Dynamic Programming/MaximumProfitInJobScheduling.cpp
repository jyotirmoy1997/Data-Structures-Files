#include<bits/stdc++.h>
using namespace std;
int func(int index, int n, vector<vector<int>> &intervals, vector<int>& startTime, vector<int> &dp){
    if(index == n)
        return 0;

    if(dp[index] != -1)
        return dp[index];


    // Not Take Case
    int currProfitNotTake = func(index+1, n, intervals, startTime, dp);

    // Take Case
    int j = lower_bound(startTime.begin(), startTime.end(), intervals[index][1]) - startTime.begin();
    int currProfitTake = intervals[index][2] + func(j, n, intervals, startTime, dp);

    return dp[index] = max(currProfitTake, currProfitNotTake);
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> intervals;
    for(int i=0; i<n; i++)
        intervals.push_back({startTime[i], endTime[i], profit[i]});

    sort(intervals.begin(), intervals.end());
    sort(startTime.begin(), startTime.end());
    vector<int> dp(n, -1);
    return func(0, n, intervals, startTime, dp);
}
int main(){
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    cout << jobScheduling(startTime, endTime, profit);
}