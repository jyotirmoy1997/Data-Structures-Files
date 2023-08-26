
#include<bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &arr){
    int n = arr.size();
    int index = -1;
    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1)
        reverse(arr.begin(), arr.end());

    else{
        for(int i=n-1; i>= index+1; i--){
            if(arr[i] > arr[index]){
                swap(arr[i], arr[index]);
                break;
            }
        }
        reverse(arr.begin() + index + 1, arr.end());
    }
    
}   
int main(){
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    // vector<int> arr = {5, 4, 3, 2, 1};
    nextPermutation(arr);
    for(int it : arr){
        cout << it << " ";
    }

    // vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
}