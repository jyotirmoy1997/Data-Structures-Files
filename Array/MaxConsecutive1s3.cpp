#include<bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k){
    int l = 0, r = 0, n = nums.size(), count = 0, maxCount = 0;
    while(r < n){
        if(nums[r] == 0)
            count++;

        while(count > k){
            if(nums[l] == 0)
                count--;
            
            l++;
        }
        if(count == k)
            maxCount = max(maxCount, r - l + 1);

        r++;
    }
    return maxCount;
}
int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << longestOnes(nums, k);
}