#include <bits/stdc++.h>
using namespace std;
int trapRainWater(int arr[], int n)
{
    /* The Idea is to compute the left max and right max for each element.
    Now, to save time, we can precompute the left max and right max for each element
    and store it in an array */
	int res = 0, lmax[n], rmax[n];
    
    // Computing Lmax
    lmax[0] = arr[0];
    for(int i=1; i<n; i++){
        lmax[i] = max(lmax[i-1], arr[i]);
    }

    // Computing Rmax
    rmax[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        rmax[i] = max(rmax[i+1], arr[i]);
    }
    
    // Subtract the array element from the minimum of lmax and rmax
    for(int i=1; i<n-1; i++)
    {
        res += min(lmax[i], rmax[i]) - arr[i];
    }

    return res;
}
int main() {
	int arr[] = {5, 0, 6, 2, 3};
	cout << trapRainWater(arr, sizeof(arr)/sizeof(int));
	return 0;
}
