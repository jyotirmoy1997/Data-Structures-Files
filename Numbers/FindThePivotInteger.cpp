#include<bits/stdc++.h>
using namespace std;
int pivotInteger(int n) {
    int sum = n * (n + 1) / 2;
    double a = sqrt(sum);

    if (a - ceil(a) == 0)
        return int(a);
    
    return -1;
}
int main(){
    cout << pivotInteger(8);
}