#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int r = min(m-1, n-1);
    long long res = 1;
    for(int i=0; i<r; i++){
        res *= N - i;
        res /= i + 1;
    }
    return (int)res;
}
int main(){
    cout << uniquePaths(3, 3);
}