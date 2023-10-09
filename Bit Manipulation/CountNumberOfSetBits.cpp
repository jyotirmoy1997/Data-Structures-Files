#include<bits/stdc++.h>
using namespace std;
int countbits(int n){
    int count = 0;
    while(n != 0){
        if(n & 1 == 1)
            count++;
        
        n = n >> 1;
    }
    return count;
}
int main(){
    cout << countbits(13);
}