#include<bits/stdc++.h>
using namespace std;
vector<bool> sieveOfEratosthenes(int n){
    vector<bool> arr(n+1, true);
    arr[0] = arr[1] = false;
    for(int i=2; i*i<=n; i++){
        if(arr[i]){
            for(int j=i*i; j<=n; j+=i){
                arr[j] = false;
            }
        }
    }
    return arr;
}
vector<int> primefactors(int n){
    vector<int> res;
    auto arr = sieveOfEratosthenes(n);
    for(int i=2; i<=n; i++){
        if(arr[i] && n % i == 0)
            res.push_back(i);
    }
    return res;
}
int main(){
    auto res = primefactors(13);
    for(auto it : res){
        cout << it << " ";
    }
}