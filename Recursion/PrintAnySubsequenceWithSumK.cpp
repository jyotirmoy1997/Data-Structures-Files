#include<bits/stdc++.h>
using namespace std;
bool printSubsequences(vector<int> &temp, vector<int> &arr, int sum, int n, int index, int K){
    if(index == n){
        if(sum == K){
            for(auto it : temp)
                cout << it << " ";
            
            cout << endl;
            return true;
        }
        return false;
    }

    // Take Case
    temp.push_back(arr[index]);
    sum += arr[index];
    if(printSubsequences(temp, arr, sum, n, index + 1, K) == true)
        return true;

    // Not Take Case
    temp.pop_back();
    sum -= arr[index];
    if(printSubsequences(temp, arr, sum, n, index + 1, K) == true)
        return true;

    return false;
}
int main(){
    vector<int> arr = {1, 2, 1};
    vector<int> temp;
    int sum = 0, n = arr.size(), index = 0, K = 2;
    printSubsequences(temp, arr, sum, n, index, K);
}