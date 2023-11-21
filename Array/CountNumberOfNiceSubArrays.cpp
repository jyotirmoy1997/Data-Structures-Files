#include <bits/stdc++.h>
using namespace std;
int atmostK(vector<int>& nums, int k){
    int count = 0, left = 0, right = 0, maxCount = 0, n = nums.size();
    while(right < n){
        if(nums[right] % 2 != 0)
            count++;

        while(count > k){
            if(nums[left] % 2 != 0)
                count--;
            
            left++;
        }
        
        maxCount += right - left + 1;
        right++;
    }
    return maxCount;
}
int numberOfSubarrays(vector<int>& nums, int k){
    return atmostK(nums, k) - atmostK(nums, k-1);
}
int main(){
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    cout << numberOfSubarrays(nums, 2);
}