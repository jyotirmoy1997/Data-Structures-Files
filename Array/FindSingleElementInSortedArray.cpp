#include<bits/stdc++.h>
using namespace std;
int findElementSorted(vector<int> &arr){
    int n = arr.size();
    int low = 1, high = n-2;
    if(n == 1)
        return arr[0];
    
    if(arr[0] != arr[1])
        return arr[0];

    if(arr[n-1] != arr[n-2])
        return arr[n-1];
        
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
            return mid;

        if((mid % 2 == 0 && arr[mid+1] == arr[mid]) || (mid % 2 == 1 && arr[mid-1] == arr[mid]))
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}
int main(){
   vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
   cout << findElementSorted(arr);
   
}