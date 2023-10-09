#include<bits/stdc++.h>
using namespace std;
int setBit(int n, int i){
    int mask = 1 << i;
    return (mask | n);
}
int main(){
    cout << setBit(13, 1);
}