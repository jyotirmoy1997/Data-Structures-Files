/* The idea is to find a one to one mapping between two strings.
For this, we keep two maps, One to keep the key, one to keep the value*/

#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t){
    if(s.length() != t.length())
        return false;

    unordered_map<char, char> mpp;
    unordered_map<char, int> mpp2;
    int l = s.length();
    for(int i=0; i<l; i++){
        if(mpp.find(s[i]) == mpp.end()){
            if(mpp2.find(t[i]) == mpp2.end()){
                mpp[s[i]] = t[i];
                mpp2[t[i]] = 1;
            }
            else
                return false; 
        }
        else if(mpp[s[i]] != t[i])
            return false;
    }
    return true;
}
int main(){
    string s = "egg";
    string t = "add";
}