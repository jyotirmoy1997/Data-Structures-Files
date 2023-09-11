#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k){
    vector<int> res;
    deque<int> dq;
    int n = nums.size();
    for(int i=0; i<n; i++){
        // Remove Out of Bound Elements
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();
        
        // Remove Smaller Elements from back of queue
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        // Push into dequeue
        dq.push_back(i);

        // Return the maximum element if subarray size is k
        if(i >= k-1)
            res.push_back(nums[dq.front()]);
    }
    return res;
}
int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    auto res = maxSlidingWindow(arr, 3);
    for(auto it : res)
        cout << it << " ";
}