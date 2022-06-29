#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main()
{
    int arr[] = {5, 7, 1, 8, 2, 10, 23, 21, 4};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr, n);
    for(auto it : arr)
    {
        cout << it << " ";
    }
}