#include<bits/stdc++.h>
using namespace std;
vector<int> sieveOfEratosthenes(int n){
    vector<int> arr(n+1, -1);
    for(int i=0; i<=n; i++)
        arr[i] = i;

    for(int i=2; i*i<=n; i++){
        if(arr[i] == i){
            for(int j=i*i; j<=n; j+=i){
               if(arr[j] == j)
                 arr[j] = i;
            }
        }
    }
    return arr;
}
vector<int> primefactors(int n){
    vector<int> res;
    auto arr = sieveOfEratosthenes(n);
    while(n > 1){
        int pf = arr[n];
        res.push_back(pf);
        n = n / pf;
    }
    return res;
}
int main(){
    auto res = primefactors(48);
    for(auto it : res){
        cout << it << " ";
    }
}