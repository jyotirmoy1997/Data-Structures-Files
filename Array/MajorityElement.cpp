// Boyre-Moore Voting Algorithm

#include<bits/stdc++.h>
using namespace std;
int majorityElement(int arr[], int n)
{
    // The first part finds the majority element candidate by voting
   int res = 0, count = 1;
   for(int i=1; i<n; i++)
   {
    if(arr[i] == arr[res])
    {
        count++;
    }
    else{
        count--;
    }
    if(count == 0){
        res = i;
        count = 1;
    }
   } 

   // The second part checks whether it is majority element or not
   count = 0;
   for(int i=0; i<n; i++){
    if(arr[res] == arr[i]){
        count++;
    }
   }
   if(count <= n/2){
    return -1;
   }
   return res;
}
int main()
{
    int arr[] = {6, 8, 4, 8, 8};
    cout << majorityElement(arr, sizeof(arr)/sizeof(int));
}