/* Given an array, find the maximum difference between a pair of elements i, j such that
j > i (arr[j] - arr[i])*/

#include <bits/stdc++.h>
using namespace std;
int maxdiffNaive(int arr[], int n)
{
	int res = arr[1] - arr[0];
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            res = max(res, arr[j] - arr[i]);
        }
    }
    return res;
}
int maxdiffEfficient(int arr[], int n)
{
    /* Here, we are keeping track of the minimum i value */
    int res = arr[1] - arr[0], minval = arr[0];
    for(int j=1; j<n; j++){
        res = max(res, arr[j] - minval);
        minval = min(minval, arr[j]);
    }
    return res;
}
int main() {
	int arr[] = {2, 3, 10, 6, 4, 8, 1};
	cout << maxdiffEfficient(arr, sizeof(arr)/sizeof(int));
	return 0;
}
