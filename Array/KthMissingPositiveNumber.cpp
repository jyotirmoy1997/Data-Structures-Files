#include<bits/stdc++.h>
using namespace std;
int kthMissingNumber(vector<int> &arr, int k){
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = (low+high)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k)
            low = mid + 1;
        else if(missing > k)
            high = mid - 1;
    }
    return low + k;
    /*
        Return Statement Logic => 
        Missing Number = arr[high] - (high + 1)
        Number should be added to arr[high] = Something More
        Something More = k - missing
        Number = arr[high] + k - (arr[high] - (high + 1))
        Number = arr[high] + k - arr[high] + high + 1
        Number = high + 1 + k
        Number = low + k (As High + 1 = Low)
    */
}
int main(){
   vector<int> arr = {2,3,4,7,11};
   cout << kthMissingNumber(arr, 5);
}