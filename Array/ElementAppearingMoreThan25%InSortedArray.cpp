#include<bits/stdc++.h>
using namespace std;
int findSpecialInteger(vector<int>& arr){
    int count = 1, start = 0, end = 1, n = arr.size();
    if(n == 1)
        return arr[0];

    while(end < n){
        if(count > n/4)
            return arr[start];  

        if(arr[start] == arr[end])
            count++;
        
        else{
            start = end;
            count = 1;
        }
        end++;
    }
    return -1;
}
int main(){
    vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    cout << findSpecialInteger(arr);
}