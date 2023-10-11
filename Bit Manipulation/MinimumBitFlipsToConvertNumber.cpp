/* The Idea is to find the Number of bits the two numbers differs.

    We can easily figure that out by performing a XOR operation.
    After the XOR operation, the number of differ bits will be set.
    After that, we simply count the number of set bits.

*/

#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n){
    int count = 0;
    while(n != 0){
        if(n & 1 == 1)
            count++;
        
        n = n >> 1;
    }
    return count;
}
int minBitFlips(int start, int goal){
    int XOR = start ^ goal;
    return countSetBits(XOR);
}
int main(){
    cout << minBitFlips(10, 7);
}