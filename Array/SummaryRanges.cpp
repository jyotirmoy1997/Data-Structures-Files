#include<bits/stdc++.h>
using namespace std;
vector<string> summaryRanges(vector<int> &nums){
    vector<string> ans;
    int start = 0, end = 1, c = 0, n = nums.size();
    if(n == 0)
        return ans;

    while(end < n){
        if(nums[end] != nums[c] + 1){
            if(start == c)
                ans.push_back(to_string(nums[start]));
            
            else
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[c]));

            start = end;
            c = end;
        }
        else
            c++;

        end++;
    }
    if(start == c)
        ans.push_back(to_string(nums[start]));
            
    else
        ans.push_back(to_string(nums[start]) + "->" + to_string(nums[c]));
        
    return ans;
}
int main(){
    vector<int> nums = {0,1,2,4,5,7};
    auto res = summaryRanges(nums);
    for(auto it : res)
        cout << it << " ";
}