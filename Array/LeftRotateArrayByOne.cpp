#include <bits/stdc++.h>
using namespace std;
void rotateArraybyOne(int arr[], int n)
{
	int temp = arr[0];
    for(int i=1; i<n; i++)
    {   
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
int main() {
	int arr[] = {9, 8, 7, 6, 4, 2, 1, 3};
	rotateArraybyOne(arr, sizeof(arr)/sizeof(int));
    for(auto it: arr)
    {
        cout << it << " "; 
    }
	return 0;
}

