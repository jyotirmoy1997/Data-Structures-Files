#include<bits/stdc++.h>
using namespace std;
void printName(int n){
    if(n == 0)
        return;

    cout << "Joe" << " ";
    printName(n-1);
}
int main(){
    printName(5);
}