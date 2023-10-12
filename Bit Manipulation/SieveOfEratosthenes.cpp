#include<bits/stdc++.h>
using namespace std;
vector<bool> sieveOfEratosthenes(int n){
    vector<bool> arr(n+1, true);
        arr[0] = false;
        arr[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (arr[p]) {
                for (int i = p * p; i <= n; i += p) {
                    arr[i] = false;
                }
            }
        }
    return arr;
}
int main(){
    int n = 10000;
    auto res = sieveOfEratosthenes(n);

    int count = 0;
    for(int i=2; i<n; i++){
        if(res[i])
            count++;
    }

    cout << count;
}