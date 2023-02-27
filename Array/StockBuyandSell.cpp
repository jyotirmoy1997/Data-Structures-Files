#include <bits/stdc++.h>
using namespace std;
int stocks(int arr[], int n)
{
	int profit = 0;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
            profit += arr[i] - arr[i-1];
        }
    }
    return profit;
}
int main() {
	int arr[] = {7, 1, 5, 3, 6, 4};
	cout << stocks(arr, sizeof(arr)/sizeof(int));
	return 0;
}
