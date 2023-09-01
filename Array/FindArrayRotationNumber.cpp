#include<bits/stdc++.h>
using namespace std;
int findMinimum(vector<int> &arr){
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX, index = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[low] <= arr[mid]){
            if(arr[low] < mini){
                mini = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else if(arr[mid] <= arr[high]){
            if(arr[mid] < mini){
                mini = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}
int main(){
   vector<int> arr = {3,4,5,1,2};
   cout << findMinimum(arr);
}