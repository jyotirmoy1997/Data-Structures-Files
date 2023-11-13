#include<bits/stdc++.h>
using namespace std;
int func(int index, int k, int n, vector<int>& arr){
    if(index == n)
        return 0;

    int maxi = INT_MIN, maxAns = INT_MIN, len = 0;
    for(int i=index; i<min(n, index+k); i++){
        len++;
        maxi = max(maxi, arr[i]);
        int sum = len * maxi + func(i+1, k, n, arr);
        maxAns = max(sum, maxAns);
    }
    return maxAns;
}
int maxSumAfterPartitioning(vector<int>& arr, int k){
    int n = arr.size();
    return func(0, k, n, arr); 
}
int main(){
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    cout << maxSumAfterPartitioning(arr, 3);
}