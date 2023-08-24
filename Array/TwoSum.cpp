#include<bits/stdc++.h>
using namespace std;
pair<int, int> twoSum(vector<int> &arr, int n, int k){
    unordered_map<int, int> mp;
    
    for(int i=0; i<n; i++)
        mp.insert({arr[i], i});



    for(int i=0; i<n; i++){
        if(mp.find(k - arr[i]) != mp.end()){
            if(mp.at(k-arr[i]) != i)
                return make_pair(i, mp.at(k - arr[i]));
        }
    }
    return make_pair(-1, -1);
}
int main(){
   vector<int> arr = {3, 2, 4};
   int n = arr.size();
   auto it = twoSum(arr, n, 6);
   cout << it.first << " " << it.second;
}