#include<bits/stdc++.h>
using namespace std;
int countSubArraySumK(vector<int> &arr, int n, int k){
    unordered_map<int, int> preSum;
    preSum[0] = 1;
    int sum = 0, count = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        int rem = sum - k;
        count += preSum[rem];
        preSum[sum] += 1;
    }
    return count;
    
}
int main(){
   vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
   int n = arr.size();
   cout << countSubArraySumK(arr, n, 3);
}