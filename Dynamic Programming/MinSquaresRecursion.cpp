#include<bits/stdc++.h>
using namespace std;
int func(int n){
    if(n == 0)
        return 0;

    int mini = 1e9;
    for(int i=1; i*i<=n; i++)
        mini = min(mini, func(n-i*i));
    
    return mini + 1;
}
int numSquares(int n) {
    return func(n); 
}
int main(){
    cout << numSquares(12);
}