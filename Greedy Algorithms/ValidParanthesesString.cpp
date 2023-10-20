/* This is almost same as the normal approach. The twist is, we have to
keep track of the '*' character as well. There can be 3 possible scenarios
(Refer to notebook)

The Idea is to keep track of the */
#include<bits/stdc++.h>
using namespace std;
bool checkValidString(string s){
    stack<int> asterisk;
    stack<int> validPar;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') 
            validPar.push(i);
        if(s[i] == '*') 
            asterisk.push(i);
        if(s[i] == ')'){
            if(!validPar.empty()) 
                validPar.pop();
            else if(!asterisk.empty()) 
                asterisk.pop();
            else 
                return false;
        }
    }
    
    while(!validPar.empty() && !asterisk.empty()){
        // As we are storing indexes, we check whether the index of '(' is
        // greater than the index of '*' or not.
        if(validPar.top() > asterisk.top()) 
            return false;
        
        validPar.pop(); 
        asterisk.pop();
    }
    
    return validPar.empty();
}
int main(){
    string s = "(((*))";
    cout << checkValidString(s);
}
