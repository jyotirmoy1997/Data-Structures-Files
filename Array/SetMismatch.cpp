#include<bits/stdc++.h>
using namespace std;
vector<int> findErrorNums(vector<int>& nums){
    unordered_map<int, int> mpp;
    for(auto it : nums)
        mpp[it]++;
    
    vector<int> res;
    int n = nums.size(), repeating = -1, missing = -1;
    for(int i=1; i<=n; i++){
        if(mpp.find(i) == mpp.end())
            missing = i;

        else if(mpp[i] > 1)
            repeating = i;
    }
    res.push_back(repeating);
    res.push_back(missing);
    return res;
}
int main(){

}