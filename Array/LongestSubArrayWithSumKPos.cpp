#include<bits/stdc++.h>
using namespace std;
int longestSubArraySumK(vector<int> &arr, int n, int k){
    int start = 0, end = 0, sum = arr[0], max_length = 0;
    while(start < n){
        while(start <= end && sum > k){
            sum -= arr[end];
            end++;
        }
        if(sum == k)
            max_length = max(max_length, start - end + 1);

        start++;
        if(start < n)
            sum += arr[start];   
    }
    return max_length;
}
int main(){
   vector<int> arr = {2, 3, 5, 1, 9};
   int n = arr.size();
   cout << longestSubArraySumK(arr, n, 10);
}