#include<bits/stdc++.h>
using namespace std;
bool checkMinHeap(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n/2; i++){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && right < n){
            if(arr[i] > arr[left] || arr[i] > arr[right])
                return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr = {1, 2, 3, 6, 7, 8};
    cout << checkMinHeap(arr);
}