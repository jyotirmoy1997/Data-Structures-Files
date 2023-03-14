#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubsequence(vector<int> &arr){
    int n = arr.size();
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);
    int maximum = 1;

    // Part for finding out the Longest Increasing Subsequence
    for(int index=0; index<=n-1; index++){
        for(int prev= 0; prev<index; prev++){
            if(arr[prev] < arr[index] && 1 + dp1[prev] > dp1[index]){
                dp1[index] = 1 + dp1[prev];
            }
            
        }
    }

    // Part for finding out the Longest Decreasing Subsequence
    for(int index=n-1; index>=0; index--){
        for(int prev= n-1; prev > index; prev--){
            if(arr[prev] < arr[index] && 1 + dp2[prev] > dp2[index]){
                dp2[index] = 1 + dp2[prev];
            }
            
        }
    }

    for(int i=0; i<n; i++){
        maximum = max(maximum, dp1[i] + dp2[i] - 1);
    }
    return maximum;
}
int main(){
    vector<int> arr = {10, 9, 2, 3, 5, 7, 101, 18};
    cout << endl << "Length :: " << longestBitonicSubsequence(arr);
}