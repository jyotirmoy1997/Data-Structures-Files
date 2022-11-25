/* Given a Binary Array, the task is to find the number of 1s.
Here, we use the first occurrence function and then calculate the 
difference between the first occurrence and the last index */

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
int countOnes(int arr[], int n){
    int pos = firstOcc(arr, n, 1);
    if(pos == -1)
        return pos;
    else 
        return n-pos;
}
int main()
{
    int arr[] = {0, 0, 0, 1, 1, 1};
    cout << countOnes(arr, sizeof(arr)/sizeof(int));
}