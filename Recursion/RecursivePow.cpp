/* The Idea is to follow a divide and conquer approach and compute only upto the half of 
the res. If the result is an odd number, we simply multiply it with the number itself*/

#include<bits/stdc++.h>
using namespace std;
double rec(double x, int n){
    if(x == 0)
        return 0;
    
    if(n == 0)
        return 1;
    
    double res = rec(x, n/2);
    res *= res;
    return (n % 2 == 0) ? res : x * res;
}
double myPow(double x, int n){
    double res = rec(x, abs(n));
    return (n < 0) ? 1/res : res;
}
int main(){
    double x = 2;
    int n = 10;
    cout << myPow(x, n);
}