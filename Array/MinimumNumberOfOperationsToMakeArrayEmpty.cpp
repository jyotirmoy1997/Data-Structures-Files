#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums){
    unordered_map<int, int> mpp;
    for(auto it : nums)
        mpp[it]++;

    int minOps = 0;
    for(auto it : mpp){
        if(it.second == 1)
            return -1;
        
        minOps += ceil(it.second * 1.0 / 3);
    }
    return minOps;
}
int main(){

}