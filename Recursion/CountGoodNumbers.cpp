
#include<bits/stdc++.h>
using namespace std;
# define MOD 1000000007
long long pow(long long x, long long n){
    if(n == 0)
        return 1;
    
    long long res = pow(x, n/2);
    res *= res;
    res %= MOD;
    if(n % 2 == 1){
        res *= x;
        res %= MOD;
    }
    return res;
}
int countGoodNumbers(long long n){
    long long even = n / 2;
    long long odd = (n / 2) + (n % 2);
    return (int)(pow(5, even) * pow(4, odd)) % MOD;
}
int main(){
    long long n = 50;
    cout << countGoodNumbers(n);
}