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
int upperBound(vector<int> &arr, int x){
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
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
pair<int, int> floorCeiling(vector<int> &arr, int x){
    return make_pair(lowerBound(arr, x), upperBound(arr, x));
}
int main(){
    vector<int> arr = {5,7,7,8,10};
    auto ans = floorCeiling(arr, 8);
    cout << "Floor :: " << ans.first << endl << "Ceiling :: " << ans.second;

}