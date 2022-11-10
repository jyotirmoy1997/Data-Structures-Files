#include <bits/stdc++.h>
using namespace std;
void frequencies(int arr[], int n)
{
	int freq = 1;
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            freq++;
        }
        else if(arr[i] != arr[i-1]){
            cout << arr[i-1] << " - " << freq << endl;
            freq = 1;
        }
    }
    cout << arr[n-1] << " - " << freq;
}
int main() {
	int arr[] = {10, 10, 10, 20, 20, 30};
	frequencies(arr, sizeof(arr)/sizeof(int));
	return 0;
}
