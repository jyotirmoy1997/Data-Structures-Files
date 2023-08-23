#include<bits/stdc++.h>
using namespace std;
int removeDuplicatesBruteForce(int arr[], int n){
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    int index = 0;
    for(auto it : st){
        arr[index] = it;
        index++;
    }
    return index;
}
int removeDuplicatesOptimal(int arr[], int n){
    int i=0, j=1;
    while(j < n){
        if(arr[i] != arr[j]){
            arr[++i] = arr[j];
        }
        j++;
    }
    return i+1;
}
int main(){
   int arr[] = {1, 1, 2, 2, 2, 3, 3};
   int n = sizeof(arr)/sizeof(int);
   cout << removeDuplicatesOptimal(arr, n) << endl;
   for(auto it : arr){
        cout << it << " ";
   }
}