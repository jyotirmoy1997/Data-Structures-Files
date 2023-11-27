#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s){
    int lastIndex = s.length();
    while(isspace(s[lastIndex]))
        lastIndex--;

    int end = lastIndex;
    while(lastIndex >= 0 && !isspace(s[lastIndex]))
        lastIndex--;

    int start = (lastIndex < 0) ? 0 : lastIndex;
    return end - start;
}
int main(){
    string s = "a";
    cout << lengthOfLastWord(s);
}