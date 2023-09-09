#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums){
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for(int i=2*n - 1; i>=0; i--){
        while(!st.empty() && nums[i%n] >= st.top())
            st.pop();
        
        if(i < n){
            if(!st.empty())
                res[i] = st.top();
        }
        st.push(nums[i%n]);
    }
    return res;
}
int main()
{
    vector<int> nums1 = {1, 3, 4, 2};
    auto res = nextGreaterElement(nums1);
    for(auto it : res)
        cout << it << " ";
}