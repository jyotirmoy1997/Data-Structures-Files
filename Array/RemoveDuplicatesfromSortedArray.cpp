/* Given a sorted array with duplicates, the task is to delete duplicates and
return the size of array containing only distinct elements*/
#include<bits/stdc++.h>
using namespace std;
int removeDuplicatesNaive(int arr[], int n)
{
    // This is the naive approach. TC => O(n), SC => O(n)
    int temp[n], res=1;
    temp[0] = arr[0];
    for(int i=1; i<n; i++){
        if(temp[res-1]!=arr[i]){
            temp[res] = arr[i];
            res++;
        }
    }
    for(int i=0; i<res; i++){
        arr[i] = temp[i];
    }
    return res;
}
int removeDuplicatesEfficient(int arr[], int n)
{
    // This is the efficient approach. TC => O(n), SC => O(1)
    int res = 1;
    for(int i=1; i<n; i++){
        if(arr[res-1] != arr[i]){
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
int main()
{
    int arr[] = {10, 20, 20, 30, 30, 30};
    cout << removeDuplicatesEfficient(arr, sizeof(arr)/sizeof(int));
	return 0;
}