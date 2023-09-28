#include<bits/stdc++.h>
using namespace std;
int smallestSubArraySumK(vector<int> &arr, int n, int k){
    unordered_map<int, int> mpp;
    int sum = 0;
    int res = INT_MAX;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == k)
            res = min(res, i+1);
        
        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int l = i - mpp[rem];
            res = min(res, l);
        }
        mpp[sum] = i;
    }
    return res;
}
int main(){
   vector<int> arr = {-8, -8, -3, 8};
   int n = arr.size();
   cout << smallestSubArraySumK(arr, n, 5);
}