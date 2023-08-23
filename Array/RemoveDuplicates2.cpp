// Approach => https://www.youtube.com/watch?v=drbtmYjZQHQ


#include<bits/stdc++.h>
using namespace std;
int removeDuplicatesOptimal(vector<int> & arr){
    int i = 0;
    for (int n : arr)
    if (i < 2 || n > arr[i-2]){
        arr[i] = n;
        i++;
    }
        
    return i;
}
int main(){
   vector<int> arr = {0,0,1,1,1,1,2,3,3};
   cout << removeDuplicatesOptimal(arr) << endl;
   for(auto it : arr){
        cout << it << " ";
   }
}