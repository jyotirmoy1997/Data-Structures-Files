#include<bits/stdc++.h>
using namespace std;
bool func(int index, int target, vector<int> &arr){
    if(target == 0)
        return true;
    
    // If some target is still left, then it has to be equal to the 0th element.
    // Else we return false stating that the target cannot be achieved.
    if(index == 0)
        return (arr[0] == target);

    bool notTake = func(index-1, target, arr);
    bool take = false;
    if(target >= arr[index])
        take = func(index-1, target-arr[index], arr);

    return notTake || take;
}
int main(){
    vector<int> arr = {1, 2, 3, 4};
    cout << func(arr.size()-1, 10, arr);
}