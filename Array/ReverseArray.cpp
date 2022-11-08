#include<bits/stdc++.h>
using namespace std;
void reverse(int arr[], int n){
    int high = n-1, low = 0;
    while(low < high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
int main()
{
    int arr[] = {1, 4, 6, 8, 10, 12};
    reverse(arr, sizeof(arr)/sizeof(int));
    for(auto it : arr){
        cout << it << " ";
    }
	return 0;
}