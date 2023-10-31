#include<bits/stdc++.h>
using namespace std;
void printSubsequences(vector<int> &temp, vector<int> &arr, int sum, int n, int index, int K){
    if(index == n){
        if(sum == K){
            for(auto it : temp)
                cout << it << " ";
            
            cout << endl;
        }
        return;
    }

    // Take Case
    temp.push_back(arr[index]);
    sum += arr[index];
    printSubsequences(temp, arr, sum, n, index + 1, K);

    // Not Take Case
    temp.pop_back();
    sum -= arr[index];
    printSubsequences(temp, arr, sum, n, index + 1, K);
}
int main(){
    vector<int> arr = {1, 2, 1};
    vector<int> temp;
    int sum = 0, n = arr.size(), index = 0, K = 2;
    printSubsequences(temp, arr, sum, n, index, K);
}