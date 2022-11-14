#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(int arr[], int n)
{
   int max_count, count;
   if(arr[0] == 1){
    count = 1;
    max_count = 1;
   }
   else{
    count = 0;
    max_count = 0;
   }
   for(int i=1; i<n; i++){
    if(arr[i] == 1){
        count++;
    }
    else{
        count = 0;
    }
    max_count = max(max_count, count);
   }
   return max_count;
}
int main()
{
    int arr[] = {0, 1, 1, 1, 1, 0, 1, 1, 0};
    cout << maxConsecutiveOnes(arr, sizeof(arr)/sizeof(int));
}