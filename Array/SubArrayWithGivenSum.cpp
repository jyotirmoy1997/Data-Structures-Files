/* Given an array, the task is to find if there exist a sub array with a 
given sum */

#include<bits/stdc++.h>
using namespace std;
bool subArraySum(int arr[], int n, int given_sum){
    int sum = arr[0], c=0;
    for(int i=1; i<n; i++){
        sum += arr[i];
        while(sum > given_sum){
            sum -= arr[c++];
        }
        if(sum == given_sum)
            return true;
    }
    return false;
}
int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    cout << subArraySum(arr, sizeof(arr)/sizeof(int), 28);
}