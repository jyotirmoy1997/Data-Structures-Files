#include<bits/stdc++.h>
using namespace std;
int longestMountain(vector<int>& arr) {
    int n = arr.size();
    if(n < 3)
        return 0;

    int prev = INT_MAX;
    int next;
    int maxi = 0;
    int curr_length = 1;
    bool flag = false;
    for(int i=0; i<n; i++){
        next = (i + 1 < n) ? arr[i+1] : INT_MAX;
        cout << prev << " " << arr[i] << " " << next << " -> " << curr_length << " -> " << maxi << endl;
        if((prev < arr[i] && arr[i] > next) || 
            (prev < arr[i] && arr[i] < next) || 
            (prev > arr[i] && arr[i] > next)){
                curr_length++;
            }
        else if(prev == arr[i]){
            if(arr[i] > next)
                curr_length = INT_MIN;
            else
                curr_length = 1;

            cout << "Inside >> ";
            cout << "Reach ";
            cout << prev << " " << arr[i] << " " << next << " -> " << curr_length << " -> " << maxi << endl;
        }
        else if(prev > arr[i] && arr[i] <= next){
            maxi = max(maxi, curr_length + 1);
            curr_length = 1;
        }
        if(prev < arr[i] && arr[i] > next)
            flag = true;
        prev = arr[i];
    }
    return (flag) ? maxi : 0;
}
int main()
{
    vector<int> arr = {0,0,1,0,0,1,1,1,1,1};
    cout << longestMountain(arr);
}