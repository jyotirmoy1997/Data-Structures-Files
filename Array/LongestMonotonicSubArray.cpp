#include<bits/stdc++.h>
using namespace std;
int longestMonotonicSubarray(vector<int>& nums){
    int n = nums.size(), maxi = 1;
    for(int i=0; i<n; i++){
        int length = 1;
        for(int j=i; j<n-1; j++){
            int curr = nums[j];
            int next = nums[j+1];
            if(next > curr)
                length++;
            
            else
                break;
        }
        maxi = max(maxi, length);
    }
    for(int i=0; i<n; i++){
        int length = 1;
        for(int j=i; j<n-1; j++){
            int curr = nums[j];
            int next = nums[j+1];
            if(next < curr)
                length++;
            
            else
                break;
        }
        maxi = max(maxi, length);
    }
    return maxi;
        
}
int main(){
    vector<int> nums = {1,4,3,3,2};
    cout << longestMonotonicSubarray(nums);
}