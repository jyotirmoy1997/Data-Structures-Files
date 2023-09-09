#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums){
    vector<int> res(nums.size());
    stack<int> st;
    for(int i=0; i<nums.size(); i++){
        int count = 0;
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j] > nums[i])
                count++;
            
        }
        res[i] = count;
    }
    return res;
}
int main()
{
    vector<int> nums = {5, 2, 10, 4};
    auto res = nextGreaterElement(nums);
    for(auto it : res)
        cout << it << " ";
        
}