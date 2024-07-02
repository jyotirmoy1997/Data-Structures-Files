#include<bits/stdc++.h>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq;
    for(auto it : nums1)
        freq[it]++;

    vector<int> res;
    for(auto it : nums2){
        if(freq.find(it) != freq.end()){
            freq[it]--;
            res.push_back(it);
        }
        if(freq[it] == 0)
            freq.erase(it);
    }
    return res;
}
int main(){
   vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
   auto res = intersect(nums1, nums2);
   for(auto it : res)
        cout << it << " ";
}