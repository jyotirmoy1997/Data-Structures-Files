#include<bits/stdc++.h>
using namespace std;
int maxFrequencyElements(vector<int>& nums) {
   int maxFreq = -1, totCount = 0;
   unordered_map<int, int> freqMap;
   for(auto it : nums){
        freqMap[it]++;
        maxFreq = max(maxFreq, freqMap[it]);
   }
   for(auto it : freqMap){
        if(it.second == maxFreq)
            totCount += maxFreq;
   }
   return totCount;
}
int main(){
    vector<int> nums = {1,2,2,3,1,4};
    cout << maxFrequencyElements(nums);
}