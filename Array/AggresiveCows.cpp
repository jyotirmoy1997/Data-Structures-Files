#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr, int cows, int dist){
    int count = 1, last = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i] - last >= dist){
            count++;
            last = arr[i];
        }
        if(count >= cows)
            return true;
    }
    return false;
}
int maxDist(vector<int> &arr, int cows){
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());

    // Brute Force Solution =>
    // for(int i=1; i<=(maxi - mini); i++){
    //     if(isPossible(arr, cows, i))
    //         continue;
    //     else
    //         return i-1;
    // }
    // return -1;
    int low = 1, high = maxi - mini;
    while(low <= high){
        int mid = (high + low)/2;
        if(isPossible(arr, cows, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
    
}
int main(){
   vector<int> arr = {0, 3, 4, 7, 9, 10};
   cout << maxDist(arr, 4);
}