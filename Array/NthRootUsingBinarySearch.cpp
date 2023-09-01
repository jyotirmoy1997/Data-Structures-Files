// Note => Using pow() function is not recommended as it can lead to overflow
#include<bits/stdc++.h>
using namespace std;
int power(int mid, int n, int m){
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans *= mid;
        if(ans > m)
            return 2;
    }
    if(ans == m)
        return 1;
    return 0;
}
int nthRoot(int x, int n){
    int low = 1, high = x;
    while(low <= high){
        int mid = (low + high) / 2;
        int midN = power(mid, n, x);
        if(midN == 1)
            return mid;
            
        else if(midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;

}
int main(){
    cout << nthRoot(27, 3);
}
