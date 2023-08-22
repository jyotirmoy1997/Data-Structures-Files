#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void reverseArray(int arr[], int n){
    int s = 0, e = n-1;
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
int main(){
   int arr[] = {10, 3, 4, 6, 22, 45, 89};
   int n = sizeof(arr)/sizeof(int);
   reverseArray(arr, n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

}