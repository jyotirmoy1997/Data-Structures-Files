#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<int> &arr){
    if(i > j)
        return 0;

    int maximum = INT_MIN;
    for(int k=i; k<=j; k++){
        int cost = arr[i-1] * arr[k] * arr[j+1] + func(i, k-1, arr) + func(k+1, j, arr);
        maximum = max(maximum, cost);
    }
    return maximum;
}
int burstBaloons(vector<int> &arr){
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    return func(1, n, arr);
}
int main(){
    vector<int> arr = {3, 1, 5, 8};
    cout << burstBaloons(arr);
}