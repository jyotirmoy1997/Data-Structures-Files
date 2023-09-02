#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int m, int k, int days){
    int count = 0;
    int total = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= days)
            count++;
        else{
            total += (count/k);
            count = 0;
        }
    }
    total += (count/k);
    if(total >= m)
        return true;
    return false;
}
int minDays(vector<int> &arr, int m, int k){
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());

    if(m * k > arr.size())
        return -1;

    // Brute Force Approach =>
    // for(int i=mini; i<=maxi; i++){
    //     if(isPossible(arr, m, k, i))
    //         return i;
    // }
    

    // Optimal Approach => Uses Binary Search
    int low = mini, high = maxi;
    while(low <= high){
        int mid = (low+high)/2;
        if(isPossible(arr, m, k, mid))
            return mid;
        low = mid + 1; 
    }
    return -1;
}
int main(){
   vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
   cout << minDays(arr, 2, 3);
}