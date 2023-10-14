#include<bits/stdc++.h>
using namespace std;
int value(char ch){
    if(ch == 'M')
        return 1000;

    else if(ch == 'D')
        return 500;

    else  if(ch == 'C')
        return 100;

    else if(ch == 'L')
        return 50;
    
    else if(ch == 'X')
        return 10;
    
    else if(ch == 'V')
        return 5;
    
    else if(ch == 'I')
        return 1;
}
int romanToInt(string s){
    if(s.length() < 2)
        return(value(s[0]));

    int l = s.length(), i=1, num =0;
    while(i < l){
        if(value(s[i-1]) >= value(s[i])){
            num += value(s[i-1]);
            i++;
        }
        else if(value(s[i-1]) < value(s[i])){
            num += value(s[i]) - value(s[i-1]);
            i += 2;
        }
    }
    if(i == l)
        num += value(s[i-1]);

    return num;
}
int main(){
    string s = "MCMXCIV"; // 1776
    cout << romanToInt(s);
}