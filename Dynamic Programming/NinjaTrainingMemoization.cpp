#include<bits/stdc++.h>
using namespace std;
int func(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if(day == 0)
    {
        int maximum = 0;
        for(int task=0; task<3; task++){
            if(task != last){
                maximum = max(maximum, arr[0][task]);
            }
        }
        return maximum;
    }

    if(dp[day][last] != -1)
        return dp[day][last];

    int maximum = 0;
    for(int task=0; task <3; task++){
        if(task != last){
            int point = arr[day][task] + func(day-1, task, arr, dp);
            maximum = max(point, maximum);
        }
    }
    return dp[day][last] = maximum;
}
int main(){
    vector<vector<int>> vec{
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6}
    };
    vector<vector<int>> dp(vec.size(), vector<int> (4, -1));
    cout << func(vec.size()-1, 3, vec, dp);
}