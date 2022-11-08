#include <bits/stdc++.h>
using namespace std;
void rightrotateArraybyOne(int arr[], int n)
{
	int temp = arr[n-1];
    for(int i=n-1; i>=0; i--)
    {   
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " "; 
    }
}
int main() {
	int arr[] = {9, 8, 7, 6, 4, 2, 1, 3};
	rotateArraybyOne(arr, sizeof(arr)/sizeof(int));
    
	return 0;
}

