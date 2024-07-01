#include<bits/stdc++.h>
using namespace std;
bool threeConsecutiveOdds(vector<int>& arr){
   int n = arr.size();
   if(n < 3)
        return false;

    int i1 = 0, i2 = 1, i3 = 2;
    while(i3 < n){
        if(arr[i1] % 2 != 0 && arr[i2] % 2 != 0 && arr[i3] % 2 != 0)
            return true;
        
        i1++;
        i2++;
        i3++;
    }     

    return false;
}
int main(){

}