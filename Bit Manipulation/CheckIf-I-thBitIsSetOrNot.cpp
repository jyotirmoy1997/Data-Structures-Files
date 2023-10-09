#include<bits/stdc++.h>
using namespace std;
bool checkIfithBitIsSet(int n, int i){
    int mask = 1 << i;
    return (mask & n);
}
int main(){
    cout << checkIfithBitIsSet(13, 1);
}