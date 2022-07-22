#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int b, int e)
{
    int pivot = arr[b];
    int start = b + 1;
    int end = e;
    while(start < end)
    {
        while(arr[start] <= pivot && start < end)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    arr[b] = arr[end];
    arr[end] = pivot;
    return end;
}
void quickSort(int arr[], int b, int e)
{
    if(e >= b)
    {
        int l = partition(arr, b, e);
        quickSort(arr, b, l-1);
        quickSort(arr, l+1, e);
    }
}
int main()
{
    int arr[] = {4, 9, 5, 3, 10, 33, 54, 36, 42, 13, 1, 0};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr, 0, n-1);
    for(auto it : arr)
    {
        cout << it << " ";
    }
}