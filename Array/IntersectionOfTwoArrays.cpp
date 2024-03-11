#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> st1;
    unordered_set<int> st2;
    for(auto it : nums1)
        st1.insert(it);

    for(auto it : nums2){
        if(st1.find(it) != st1.end())
            st2.insert(it);
    }
    vector<int> res(st2.begin(), st2.end());
    return res;
}
int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    auto res = intersection(nums1, nums2);
    for(auto it : res)
        cout << it << " ";
}