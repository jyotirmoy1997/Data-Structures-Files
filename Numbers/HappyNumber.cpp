#include<bits/stdc++.h>
using namespace std;
int getNext(int n){
    int sum = 0;
    while(n > 0){
        int digit = n % 10;
        sum += pow(digit, 2);
        n /= 10;
    }
    return sum;
}
bool isHappy(int n){
    unordered_set<int> st;
    while(st.find(n) == st.end()){
        if(n == 1)
            return true;

        st.insert(n);
        n = getNext(n);
    } 
    return false;
}
int main(){
    cout << isHappy(19);
}