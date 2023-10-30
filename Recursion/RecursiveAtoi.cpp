#include<bits/stdc++.h>
using namespace std;
int rec(string s, int i, int res, int sign){
    if(i >= s.length() || s[i] < '0' || s[i] > '9')
        return sign * res;

    int temp = s[i] - '0';

    if(res > INT_MAX / 10 || res == INT_MAX / 10 && temp > 7)
        return (sign > 0) ? INT_MAX : INT_MIN;

    return rec(s, i + 1, res * 10 + temp, sign);
}
int myAtoi(string s){
    int i=0, sign = 1, res = 0, l = s.length();

    // Trim down leading whitespaces
    while(i < l && isspace(s[i]))
        i++;
    
    // Check for Sign
    if(i < l && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    return rec(s, i, res, sign);
}
int main(){
    string s = " 12350.0234 2.36  Word S"; // 1776
    cout << myAtoi(s);
}