#include<bits/stdc++.h>
using namespace std;
int subArrayXORK(vector<int> &arr, int n, int k){
   unordered_map<int, int> mp;
   int count = 1, xr = 0;
   mp[0] = 1;
   for(int i=0; i<n; i++){
        xr ^= arr[i];
        int x = xr ^ k;
        count += mp[x];
        mp[xr] = 1;
   }
   return count;
}
int main(){
   vector<int> arr = {4, 2, 2, 6, 4};
   int n = arr.size();
   cout << subArrayXORK(arr, n, 6);
}