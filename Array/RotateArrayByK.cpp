#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> & arr, int ind1, int ind2){
    while(ind1 < ind2){
        swap(arr[ind1], arr[ind2]);
        ind1++;
        ind2--;
    }
}
void rightrotateArraybyKBruteForce(int arr[], int n, int k)
{
	vector<int> nums(k);
    int c = 0;
    for(int i=n-k; i<n; i++){
        nums[c] = arr[i];
        c++;
    }
    for(int i=n-k-1; i>=0; i--){
        arr[i+k] = arr[i];
    }
    for(int i=0; i<k; i++){
        arr[i] = nums[i];
    }
}
void rightrotateArrayByKOptimal(vector<int> & arr, int n, int k){
    reverse(arr, 0, n-k-1);
    reverse(arr, n-k, n-1);
    reverse(arr, 0, n-1);
}
int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
	rightrotateArrayByKOptimal(arr, sizeof(arr)/sizeof(int), 3);
    for(auto it : arr){
        cout << it << " ";
    }
	return 0;
}

