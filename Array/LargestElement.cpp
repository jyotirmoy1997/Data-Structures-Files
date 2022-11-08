#include <bits/stdc++.h>
using namespace std;
int largestElement(int arr[], int n)
{
	int largestEl = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > largestEl){
            largestEl = arr[i];
        }
    }
    return largestEl;
}
int main() {
	int arr[] = {9, 8, 7, 6, 674, 2, 1, 3};
	cout << largestElement(arr, sizeof(arr)/sizeof(int));
	return 0;
}
