#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int l, int h){
    if(l > h)
        return;
    
    swap(arr[l], arr[h]);
    reverse(arr, l + 1, h - 1);
}
int main(){
    vector<int> arr = {7, 3, 2, 5, 4, 9};
    reverse(arr, 0, arr.size()-1);
    for(auto it : arr)
        cout << it << " ";
}