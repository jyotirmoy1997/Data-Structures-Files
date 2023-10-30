#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int l, int h){
    if(l > h)
        return true;

    if(str[l] != str[h])
        return false;
    
    return isPalindrome(str, l + 1, h - 1);
}
int main(){
    string str = "TENBT";
    cout << isPalindrome(str, 0, str.length()-1);
}