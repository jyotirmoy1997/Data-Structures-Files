/* This is also a variation of the activity selection problem

    Here, the absolute order of arrival and departure is not important.
    We just have to find when a train is arriving and when a train is departing.

    Step 1 : Sort the Arrival Time and Departure Time in Ascending Order

*/
#include<bits/stdc++.h>
using namespace std;
int findPlatform(vector<int> &arr, vector<int> &dep, int n){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 1, maxi = 1, platforms = 1, j = 0;
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            platforms++;
            i++;
        }
        else if(arr[i] > dep[j]){
            platforms--;
            j++;
        }
        maxi = max(maxi, platforms);
    }
    return maxi;
}
int main(){
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    int n = arr.size();
    cout << findPlatform(arr, dep, n);
}