#include<bits/stdc++.h>
using namespace std;
int min(int arr[], int start, int end)
{
    int min_index = start;
    for(int i=start; i<end; i++)
    {
        if(arr[i] < arr[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}
void selectionSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j = min(arr, i, n);
        if(i != j)
        {
            swap(arr[i], arr[j]);
        }
    }
}
int main()
{
    int arr[] = {5, 7, 1, 8, 2, 10, 23, 21, 4};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr, n);
    for(auto it : arr)
    {
        cout << it << " ";
    }
}