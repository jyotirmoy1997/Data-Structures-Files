#include<bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k){
    priority_queue<int> pq;
    for(auto it : nums)
        pq.push(it);
    
    for(int i=0; i<k-1; i++)
        pq.pop();

    return pq.top();
}
int main(){
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, 2);
}