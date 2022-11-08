#include<bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n){
    for(int i=0; i<n-1; i++){
        if(arr[i+1] < arr[i])
            return false;
    }
    return true;
}
int main()
{
    int arr[] = {1, 4, 6, 8, 10, 12};
    cout << isSorted(arr, sizeof(arr)/sizeof(int));
	return 0;
}