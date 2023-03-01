#include<bits/stdc++.h>
using namespace std;
int func(int index, int prev, vector<int> &arr){
    if(index == arr.size()) 
        return 0;

    // Take Case
    int take = INT_MIN;
    if(prev == -1 || arr[prev] < arr[index])
        take = 1 + func(index+1, index, arr);
    
    int notTake = 0 + func(index+1, prev, arr);

    return max(take, notTake);
}
int longestIncreasingSubsequence(vector<int> &arr){
    return func(0, -1, arr);
}
int main(){
    vector<int> arr = {10, 9, 2, 3, 5, 7, 101, 18};
    cout << longestIncreasingSubsequence(arr);
}