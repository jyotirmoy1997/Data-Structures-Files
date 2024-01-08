#include<bits/stdc++.h>
using namespace std;
int numberOfArithmeticSlices(std::vector<int>& nums) {
    int n = nums.size();
    int totCount = 0;

    vector<unordered_map<int, int>> dp(n);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long diff = (long long)(nums[i]) - nums[j]; 

            if (diff > INT_MAX || diff < INT_MIN)
                continue; 

            int diff_int = (int)(diff);

            dp[i][diff_int] += 1; 

            if (dp[j].find(diff_int) != dp[j].end()) {
                dp[i][diff_int] += dp[j][diff_int];
                totCount += dp[j][diff_int];
            }
        }
    }
    return totCount;
}     
int main(){
    vector<int> nums = {2, 4, 6, 8, 10};
    cout << numberOfArithmeticSlices(nums);
}