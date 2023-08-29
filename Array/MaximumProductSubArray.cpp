#include <bits/stdc++.h>
using namespace std;
int maxProductSubarray(vector<int> &arr){
    int maximum = INT_MIN, prefix = 1, suffix = 1;
    int n = arr.size();
    for(int i=0; i<arr.size(); i++){
        if(prefix == 0)
            prefix = 1;
        if(suffix == 0)
            suffix = 1;
        
        prefix *= arr[i];
        suffix *= arr[n-i-1];
        maximum = max(maximum, max(prefix, suffix));
    }
    return maximum;
}
int main() {
	vector<int> arr = {2, 3, -2, 4};
	cout << maxProductSubarray(arr);
	return 0;
}
