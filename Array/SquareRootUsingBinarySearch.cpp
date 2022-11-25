#include<bits/stdc++.h>
using namespace std;
int squareRoot(int x){
    int low = 1, high = x, res = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid * mid == x)
            res = mid;
        else if(mid * mid > x)
            high = mid - 1;
        else{
            low = mid + 1;
            res = mid;
        }
    }
    return res;
}
int main(){
    cout << squareRoot(12);
}
