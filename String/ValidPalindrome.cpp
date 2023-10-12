#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
    string s1 = "";
    for(auto it : s){
        if(iswalnum(it))
            s1 += tolower(it);
    }
    int l = 0;
    int h = s1.length()-1;
    while(l < h){
        if(s1[l] != s1[h])
            return false;

        l++;
        h--;
    }
    return true;
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
}