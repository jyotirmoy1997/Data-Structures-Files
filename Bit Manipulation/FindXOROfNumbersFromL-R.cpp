#include<bits/stdc++.h>
using namespace std;
int XORVal(int n){
    if(n % 4 == 0)
        return n;

    else if(n % 4 == 1)
        return 1;
    
    else if(n % 4 == 2)
        return n+1;
    
    else if(n % 4 == 3)
        return 0;
}
int XORLR(int L, int R){
    int RXOR = XORVal(R);
    int LXOR = XORVal(L-1);

    return RXOR ^ LXOR;
}
int main(){
    cout << XORLR(3, 6);
}