#include<bits/stdc++.h>
using namespace std;
void sortColorsBruteForce(vector<int> &arr){
    int zeros = 0, ones = 0, twos = 0;
    for(auto it : arr){
        if(it == 0)
            zeros++;
        else if(it == 1)
            ones++;
        else
            twos++;
    }
    // cout << zeros << ones << twos << endl;
    int n = arr.size();
    int k = 0;
    while(k < zeros){
        arr[k++] = 0; 
    }
    while(k < ones + zeros){
        arr[k++] = 1; 
    }
    while(k < twos + ones + zeros){
        arr[k++] = 2; 
    }

}

void sortColorsOptimal(vector<int> &arr){

    /* This Solution is Based on The Dutch National Flag Algorithm*/

    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid < high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1)
            mid++;
        
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
            
    }
}
int main(){
   vector<int> arr = {2,0,2,1,1,0};
   int n = arr.size();
   sortColorsOptimal(arr);
   for(auto it : arr){
        cout << it << " ";
    }
}