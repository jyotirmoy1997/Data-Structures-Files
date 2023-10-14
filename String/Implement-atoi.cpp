#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
    int i = 0, sign = 1, result = 0;

    // Step 1: Ignore leading whitespace
    while (i < s.length() && isspace(s[i])) {
        i++;
    }

    // Step 2: Check for a sign character
    if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3 and 4: Parse the digits and convert to an integer
    while (i < s.length() && isdigit(s[i])) {
        int digit = s[i] - '0';

        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    // Apply the sign
    return sign * result;
}

int main(){
    string s = " 12350567780020.0234 2.36  Word S"; // 1776
    cout << myAtoi(s);
    // cout << romanToInt(s);
}