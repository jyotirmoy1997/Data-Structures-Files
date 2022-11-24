#include<bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int n, int x){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low+high) / 2;
        if(arr[mid] > x){
            high = mid - 1; 
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            if(mid == 0 || arr[mid] != arr[mid-1]){
                return mid;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 4, 6, 8, 8, 10, 12};
    cout << firstOcc(arr, sizeof(arr)/sizeof(int), 8);
}