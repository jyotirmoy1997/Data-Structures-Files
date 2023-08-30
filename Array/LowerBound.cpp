#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr, int x){
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 3, 5, 6};
    cout << lowerBound(arr, 7);
}