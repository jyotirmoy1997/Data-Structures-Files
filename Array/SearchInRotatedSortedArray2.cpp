// Array can Contain duplicate elements
#include<bits/stdc++.h>
using namespace std;
bool searchSorted(vector<int> &arr, int x){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(arr[mid] == x)
            return true;
        if(arr[low] <= arr[mid] && arr[mid] <= arr[high]){
            low++;
            high--;
            continue;
        }
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
    return false;
}
int main(){
   vector<int> arr = {2,5,6,0,0,1,2};
   cout << searchSorted(arr, 0);
   
}