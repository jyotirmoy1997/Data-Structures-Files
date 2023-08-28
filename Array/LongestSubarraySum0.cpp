#include<bits/stdc++.h>
using namespace std;
int longestSubArraySumK(vector<int> &arr, int n){
   unordered_map<int, int> mp;
   int maxLen = 0, prefixSum = 0;
   for(int i=0; i<n; i++){
        prefixSum += arr[i];
        if(prefixSum == 0)
            maxLen = max(maxLen, i+1);
        else{
            int rem = prefixSum - 0;
            if(mp.find(rem) != mp.end()){
                int l  = i - mp[rem];
                maxLen = max(maxLen, l);
            }
            else
                mp[prefixSum] = i;
        }
        
   }
   return maxLen;
}
int main(){
   vector<int> arr = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
   int n = arr.size();
   cout << longestSubArraySumK(arr, n);
}