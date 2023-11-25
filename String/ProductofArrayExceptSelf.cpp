#include<bits/stdc++.h>
using namespace std;

// Note => This uses O(N) space
// vector<int> productExceptSelf(vector<int> &nums) {
//     int n = nums.size();
//     vector<int> prefix(n, 1), suffix(n, 1), res(n);
//     prefix[0] = nums[0];
//     suffix[n - 1] = nums[n - 1];
//     for (int i = 1; i < n - 1; i++) {
//         prefix[i] = prefix[i - 1] * nums[i];
//         suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];
//     }
//     res[0] = suffix[1];
//     res[n - 1] = prefix[n - 2];
//     for (int i = 1; i < n - 1; i++)
//         res[i] = prefix[i - 1] * suffix[i + 1];

//     return res;
// }

// Optimal Approach => Uses O(1) space
vector<int> productExceptSelf(vector<int> &nums) {
     int n = nums.size();
    vector<int> result(n, 1);
    
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix = prefix * nums[i];
    }
    
    int postfix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = result[i] * postfix;
        postfix = postfix * nums[i];
    }
    
    return result;
}
int main(){
    vector<int> nums = {1, 2, 3, 4};
    auto res = productExceptSelf(nums);
    for(auto it : res)
        cout << it << " ";
}   