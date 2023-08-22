#include<bits/stdc++.h>
using namespace std;
int largest(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n-1; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main(){
   int arr[] = {10, 12, 4, 6, 4, 12, 10};
   int n = sizeof(arr)/sizeof(int);
   cout << largest(arr, n);

}