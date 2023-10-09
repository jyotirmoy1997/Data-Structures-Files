#include<bits/stdc++.h>
using namespace std;
bool isEven(int n){
    if((n & 1) == 0)
        return true;

    else
        return false;
}

int main(){
    cout << isEven(6);
}