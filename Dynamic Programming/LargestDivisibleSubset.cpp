/* This problem is a variation of the Longest Increasing Subsequence 

The only thing that changes is that first we sort the array and then
find the longest divisible subset

*/

#include<bits/stdc++.h>
using namespace std;
int longestDivisibleSubset(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    sort(arr.begin(), arr.end());
    int maximum = 1, lastIndex = 0;
    for(int index=0; index<=n-1; index++){
        hash[index] = index;
        for(int prev= 0; prev<index; prev++){
            if(arr[index] % arr[prev]  && 1 + dp[prev] > dp[index]){
                dp[index] = 1 + dp[prev];
                hash[index] = prev;
            }
            
        }
        if(dp[index] > maximum){
            maximum = dp[index];
            lastIndex = index;
        }
    }

    // Printing The LDS
    stack<int> st;
    st.push(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        st.push(arr[lastIndex]);
    }
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        cout << it << " ";
    }
    return maximum;
}
int main(){
    vector<int> arr = {10, 9, 2, 3, 5, 7, 101, 18};
    cout << endl << "Length :: " << longestDivisibleSubset(arr);
}