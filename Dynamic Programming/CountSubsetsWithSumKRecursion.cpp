#include<bits/stdc++.h>
using namespace std;
int func(int index, int target, vector<int> &arr){
    if(target == 0)
        return 1;
    
    if(index == 0)
        return (arr[0] == target) ? 1 : 0;

    int notTake = func(index-1, target, arr);
    int take = false;
    if(target >= arr[index])
        take = func(index-1, target-arr[index], arr);

    return notTake + take;
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    cout << func(arr.size()-1, 4, arr);
}