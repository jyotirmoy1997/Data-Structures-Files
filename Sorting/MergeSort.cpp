#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid-low + 1;
    int n2 = high - mid;
    int *left = new int[n1+1];
    int *right = new int[n2+1];
    for(int i=0; i<n1; i++)
    {
        left[i] = arr[low+i];
    }
    for(int i=0; i<n2; i++)
    {
        right[i] = arr[mid+i+1];
    }
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    int i=0, j=0;
    for(int k=low;k<=high;k++)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
	}
}
void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int arr[] = {5, 7, 1, 8, 2, 10};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, n);
    for(auto it : arr)
    {
        cout << it << " ";
    }
}