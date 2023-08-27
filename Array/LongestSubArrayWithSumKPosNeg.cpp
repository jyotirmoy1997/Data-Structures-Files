#include<bits/stdc++.h>
using namespace std;
int longestSubArraySumK(vector<int> &arr, int n, int k){
    map<int, int> preSum;
    int sum = 0, maxLen = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == k)
            maxLen = max(maxLen, i+1);
        
        int rem = sum - k;
        if(preSum.find(rem) != preSum.end()){
            int l = i - preSum[rem];
            maxLen = max(maxLen, l);
        }
        preSum[sum] = i;
    }
    return maxLen;
}
int main(){
   vector<int> arr = {2, 3, 5, 1, 9};
   int n = arr.size();
   cout << longestSubArraySumK(arr, n, 10);
}