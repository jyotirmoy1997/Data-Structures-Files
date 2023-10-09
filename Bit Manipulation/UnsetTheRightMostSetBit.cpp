#include<bits/stdc++.h>
using namespace std;
int setBit(int n){
    return (n & (n-1));
}
int main(){
    cout << setBit(13);
}