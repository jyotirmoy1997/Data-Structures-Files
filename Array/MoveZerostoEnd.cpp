/* Given an array, the task is to Move All the Zeros to the end maintaining the 
relative order of elements*/
#include<bits/stdc++.h>
using namespace std;
void moveZerostoEnd(int arr[], int n)
{
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[count]);
            count++;
        }
    }
}
int main()
{
    int arr[] = {10, 8, 0, 0, 12, 0};
    moveZerostoEnd(arr, sizeof(arr)/sizeof(int));
    for(auto it : arr){
        cout << it << " ";
    }
}