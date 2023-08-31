#include<bits/stdc++.h>
using namespace std;
int searchSorted(vector<int> &arr, int x){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(arr[mid] == x)
            return mid;

        if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(arr[mid] <= x && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main(){
   vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
   cout << searchSorted(arr, 3);
   
}