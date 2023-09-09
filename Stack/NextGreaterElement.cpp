#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> mpp;
    vector<int> res(nums1.size());
    for(int i=0; i<nums1.size(); i++)
        mpp[nums1[i]] = i;

    stack<int> st;
    for(int i=nums2.size()-1; i>=0; i--){
        while(!st.empty() && nums2[i] >= st.top())
            st.pop();
        
        if(st.empty() && mpp.find(nums2[i]) != mpp.end())
            res[mpp[nums2[i]]] = -1;

        else{
            if(mpp.find(nums2[i]) != mpp.end())
                res[mpp[nums2[i]]] = st.top();
        }
        st.push(nums2[i]);
    }
    return res;
}
int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    auto res = nextGreaterElement(nums1, nums2);
    for(auto it : res)
        cout << it << " ";
}