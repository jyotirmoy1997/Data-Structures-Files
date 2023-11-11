/* This problem is an extension of the longest bitonic subsequence
   
   The Array contains some elements which can form a mountain (Some elements can form
   a bitonic subsequence)

   So, if we find out the longest bitonic subsequence, i.e. the longest mountain that 
   can be formed from the array elements, then subtracting the longest mountain length 
   from the original array will give us the minimum removals we need to make.
   
   Very Important Edge Case =>

   There can be 3 types of mountain =>
   1. Decreasing
   2. Increasing
   3. Bitonic

   The dp1 and dp2 array elements which are equal to 1 are not considered when calculating 
   the longest bitonic subsequence (LBS) because they represent elements that are not part 
   of either an increasing or decreasing subsequence. These elements are typically plateaus or 
   valleys in the array, and they do not contribute to the length of a mountain array. 
   Therefore, only the dp1 and dp2 array elements that are greater than 1 are considered 
   when identifying peaks in potential bitonic subsequences.The reason for excluding elements 
   with dp1 or dp2 equal to 1 is that they represent elements that are not contributing to the
    mountain shape of the array. A mountain array requires a strictly increasing sequence 
    followed by a strictly decreasing sequence. Elements with dp1 or dp2 equal to 1 are either 
    part of a plateau or a valley, which do not contribute to the mountain shape. By excluding 
    these elements, we are ensuring that we are only considering elements that are actually part 
    of the mountain shape.

    Here's a more detailed explanation of why elements with dp1 or dp2 equal to 1 are not considered:

    Elements with dp1 equal to 1: These elements are part of a strictly increasing subsequence, 
    but they are not peaks. A peak in a mountain array is an element that is preceded by a strictly 
    increasing sequence and followed by a strictly decreasing sequence. Elements with dp1 equal to 1 
    are simply part of the strictly increasing sequence, and they do not mark the transition to the 
    decreasing sequence.Elements with dp2 equal to 1: These elements are part of a strictly decreasing 
    subsequence, but they are not peaks either. A peak in a mountain array is an element that is 
    preceded by a strictly increasing sequence and followed by a strictly decreasing sequence. 
    Elements with dp2 equal to 1 are simply part of the strictly decreasing sequence, and they do not 
    mark the transition from the increasing sequence to the decreasing sequence.

    By excluding elements with dp1 or dp2 equal to 1, we are ensuring that we are only considering 
    elements that are actually part of the mountain shape. This allows us to accurately calculate the 
    longest bitonic subsequence (LBS), which in turn allows us to calculate the minimum number of 
    removals required to make a mountain array.

*/


#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubsequence(vector<int>& nums){
    int n = nums.size();

    // Longest Increasing Subsequence 
    vector<int> dp1(n, 1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nums[i] > nums[j] && 1 + dp1[j] > dp1[i])
                dp1[i] = 1 + dp1[j];
        }
    }
    
    // Longest Decreasing Subsequence
    vector<int> dp2(n, 1);
    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(nums[i] > nums[j] && 1 + dp2[j] > dp2[i])
                dp2[i] = 1 + dp2[j];
        }
    }


    int maxi = 1;
    for(int i=0; i<n; i++){
        if(dp1[i] != 1 && dp2[i] != 1)
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}
int minimumMountainRemovals(vector<int>& nums) {
    int lengthOfLBS = longestBitonicSubsequence(nums);
    return nums.size() - lengthOfLBS;
}
int main(){
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout << minimumMountainRemovals(nums);
}