/* The basic idea is to concat the original string with itself. Now, it is guaranteed
that if the goal can be reached by rotating the original string, then the goal has to be 
a substring of the modified original string. */

#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal){
    if(s.length() != goal.length())
        return false;

    string str = s + s;
    size_t found = str.find(goal);
    
    if(found != string::npos){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s = "ohbrwzxvxe";
    string t = "uornhegseo";
    cout << rotateString(s, t);
}