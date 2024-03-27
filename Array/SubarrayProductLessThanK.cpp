/*
    Very Important : The difference between right and left pointers + 1 = The number of subarrays
    between right and left pointers

*/ 

#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int left = 0, right = 0, product = 1, count = 0, n = nums.size();
    if(k <= 1) 
        return 0;

    while (right < n) {
      product *= nums[right];
      while(product >= k){
        product /= nums[left];
        left++;
      }
      count += 1 + (right - left);
      right++;
    }
    return count; 
}
int main(){
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << numSubarrayProductLessThanK(nums, k);
}