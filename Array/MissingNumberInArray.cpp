#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &arr, int n){
    vector<int> nums(n+1, 0);
    for(int i=0; i<n; i++){
        nums[arr[i]]++;
    }
    for(int i=0; i<n+1; i++){
        if(nums[i] == 0)
            return i;
    }
}
int missingNumberXOR(vector<int> &arr, int n){
    int xor1 = 0, xor2 = 0;
    for(int i=0; i<n-1; i++){
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ (i+1);
    }
    xor2 = xor2 ^ (n - 1);
    return xor1 ^ xor2;
}
int main(){
   vector<int> arr = {9,6,4,2,3,5,7,0,1};
   int n = arr.size();
   cout << missingNumberXOR(arr, n);
}