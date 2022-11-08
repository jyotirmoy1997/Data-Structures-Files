#include <bits/stdc++.h>
using namespace std;
int secondLargestElement(int arr[], int n)
{
	int largest = 0, res = -1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] > arr[largest]){
            res = largest;
            largest = i;
        }
        else if(arr[i] != arr[largest])
        {
            if(res == -1 || arr[i] > arr[res]){
                res = i;
            }
        }
    }
    return res;
}
int main() {
	int arr[] = {9, 8, 7, 6, 674, 2, 1, 3};
	cout << secondLargestElement(arr, sizeof(arr)/sizeof(int));
	return 0;
}
