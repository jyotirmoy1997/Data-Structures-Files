#include<bits/stdc++.h>
using namespace std;
int secondLargest(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n-1; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    int second_max = arr[0];
    for(int i=1; i<n-1; i++){
        if(arr[i] > second_max && arr[i] != max)
            second_max = arr[i];
    }
    return second_max;
}
int main(){
   int arr[] = {17, 11, 2, 5, 16, 7, 29, 13};
   int n = sizeof(arr)/sizeof(int);
   cout << secondLargest(arr, n);

}