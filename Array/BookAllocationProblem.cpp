#include<bits/stdc++.h>
using namespace std;
int allocate(vector<int> &arr, int maxPages){
    int pageCount = 0, std = 1, n = arr.size();
    for(int i=0; i<n; i++){
        if(pageCount + arr[i] <= maxPages)
            pageCount += arr[i];
        else{
            std++;
            pageCount = arr[i];
        }
    }
    return std;
}
int minPages(vector<int> &arr, int m){
    int maxi = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // Brute Force Solution
    // for(int i=maxi; i<=sum; i++){
    //     if(allocate(arr, i) == m)
    //         return i;
    // }
    
    // Optimal Solution => Uses Binary Search
    int low = maxi, high = sum;
    while(low <= high){
        int mid = (high + low)/2;
        if(allocate(arr, mid) == m)
            return mid;
        else if(allocate(arr, mid) > m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int main(){
   vector<int> arr = {25, 46, 28, 49, 24};
   cout << minPages(arr, 4);
}