#include<bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums){
    int left = 0, right = 0, n = nums.size(), res = 0;
    while(right < n - 1){
        int farthest = 0;
        for(int i=left; i<=right; i++)
            farthest = max(farthest, i + nums[i]);
        
        left = right + 1;
        right = farthest;
        res++;
    } 
    return res;
}
int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);
}