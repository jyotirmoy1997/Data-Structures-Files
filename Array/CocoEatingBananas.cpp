#include<bits/stdc++.h>
using namespace std;
int countHours(vector<int> &arr, int n){
    int totalHours = 0;
    for(int i=0; i<arr.size(); i++){
        totalHours += ceil((double)arr[i] / (double)n);
    }
    return totalHours;
}
int minRate(vector<int> &arr, int h){
    int maxVal = *max_element(arr.begin(), arr.end());
    int low = 1, high = maxVal;
    while(low <= high){
        int mid = (low + high) / 2;
        int totalHours = countHours(arr, mid);
        if(totalHours <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> arr = {3,6,7,11};
    cout << minRate(arr, 8);
}