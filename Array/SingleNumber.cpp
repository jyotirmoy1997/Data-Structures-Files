// https://leetcode.com/problems/single-number/

// Approach => Use XOR Operator

#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &arr, int n){
    int num = 0;
    for(int i=0; i<n; i++)
        num = num ^ arr[i];
    
    return num;
}
int main(){
   vector<int> arr = {4,1,2,1,2};
   int n = arr.size();
   cout << singleNumber(arr, n);
}