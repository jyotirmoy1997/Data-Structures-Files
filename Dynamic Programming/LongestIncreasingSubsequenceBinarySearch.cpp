#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(vector<int> &arr){
    int n = arr.size();
    vector<int> temp;
    int len = 1;
    temp.push_back(arr[0]);
    for(int i=0; i<n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}
int main(){
    vector<int> arr = {10, 9, 2, 3, 5, 7, 101, 18};
    cout << "Length :: " << longestIncreasingSubsequence(arr);
}