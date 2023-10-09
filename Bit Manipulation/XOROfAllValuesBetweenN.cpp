/* Given N, print the XOR of all values between 1-N
    Example : 5 => 1 ^ 2 ^ 3 ^ 4 ^ 5 = 1
*/

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
int main(){
    cout << XORVal(5);
}