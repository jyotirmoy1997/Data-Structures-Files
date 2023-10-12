#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s){
    int l = s.length();

    // Step 1 : Remove Leading Spaces
    int index1 = 0;
    while(s[index1] == ' ')
        index1++;

    // Step 2 : Remove Trailing Spaces
    int index2 = l-1;
    while(s[index2] == ' ')
        index2--;

    stack<string> st;
    string ans = "";
    string prev = "";
    while(index1 <= index2){
        string p = "";
        while(s[index1] != ' ' && index1 <= index2){
            p += s[index1];
            index1++;
        }
        if(prev.size() == 0){
            prev = p;
        }
        else{
            ans = p + " " + prev;
            prev = ans;
        }
        while(s[index1] == ' ' && index1 <= index2)
            index1++;
    }
    return ans;
}
int main(){
    string s = "EPY2giL";
    cout << reverseWords(s);
}