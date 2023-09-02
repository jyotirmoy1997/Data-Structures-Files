#include<bits/stdc++.h>
using namespace std;
int daysReq(vector<int> &arr, int capacity){
    int load = 0, days = 1;
    for(int i=0; i<arr.size(); i++){
        if(load + arr[i] > capacity){
            load = arr[i];
            days++;
        }
        else{
            load += arr[i];
        }
    }
    return days;
}
int findCapacity(vector<int> &arr, int days){
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int maxi = *max_element(arr.begin(), arr.end());

    // Brute Force Solution
    // for(int i=maxi; i<=sum; i++){
    //     int days_req = daysReq(arr, i);
    //     if(days_req <= days)
    //         return i;
    // }
    // return -1;

    // Optimal Solution => Using Binary Search
    int ans = -1;
    int low = maxi, high = sum;
    while(low <= high){
        int mid = (low+high)/2;
        if(daysReq(arr, mid) <= days){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1; 
        }
    }
    return ans;
}
int main(){
   vector<int> arr = {3,2,2,4,1,4};
   cout << findCapacity(arr, 3);
}