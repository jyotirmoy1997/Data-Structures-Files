#include<bits/stdc++.h>
using namespace std;
long long largestPerimeter(vector<int>& nums){
    sort(nums.begin(), nums.end());
    long long tot = 0;
    long long ans = -1;
    for(auto i : nums) {
        if(tot > i) {
            ans = tot + i;
        }
        tot += i;
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 12, 2, 3, 5, 1, 50, 3};
    cout << largestPerimeter(nums);
}