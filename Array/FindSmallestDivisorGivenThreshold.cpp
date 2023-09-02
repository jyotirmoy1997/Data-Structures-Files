#include<bits/stdc++.h>
using namespace std;
int calculate(vector<int> &arr, int threshold, int div){
    int total = 0;
    for(int i=0; i<arr.size(); i++){
        total += ceil((double)arr[i]/(double)div);
    }
    return total <= threshold;
}
int minDivisor(vector<int> &arr, int threshold){
    int maxi = *max_element(arr.begin(), arr.end());

    // Brute Force Approach =>
    // for(int i=1; i<=maxi; i++){
    //     if(calculate(arr, threshold, i))
    //         return i;
    // }
    // return -1;
    int ans = -1;
    int low = 1, high = maxi;
    while(low <= high){
        int mid = (low+high)/2;
        if(calculate(arr, threshold, mid)){
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
   vector<int> arr = {1, 2, 5, 9};
   cout << minDivisor(arr, 6);
}