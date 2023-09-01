#include<bits/stdc++.h>
using namespace std;
int findMinimum(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[low] <= arr[mid]){
            mini = min(mini, arr[low]);
            low = mid + 1;
        }
        else if(arr[mid] <= arr[high]){
            mini = min(mini, arr[mid]);
            high = mid - 1;
        }
    }
    return mini;
}
int main(){
   vector<int> arr = {3,4,5,1,2};
   cout << findMinimum(arr);
}