#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high, int x){
    while(low <= high){
        int mid = (high + low) / 2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            high = mid -1;
        else
            low = mid + 1;
    }
    return -1;
}
int searchInfinite(int arr[], int x){
    if(arr[0] == x)
        return 0;
    int i = 1;
    while(arr[i] < x){
        i *= 2;
    }
    if(arr[i] == x){
        return i;
    }
    return binarySearch(arr, (i/2)+1, i-1, x);
}
int main(){
    int arr[] = {4, 6, 8, 10, 13, 56, 89};
    cout << searchInfinite(arr, 10);
}