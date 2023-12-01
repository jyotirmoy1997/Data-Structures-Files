#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string ransomNote, string magazine){
    unordered_map<char, int> mpp;
    for(auto it : magazine)
        mpp[it]++;

    for(auto it : ransomNote){
        if(mpp.find(it) != mpp.end()){
            mpp[it]--;
            if(mpp[it] == 0)
                mpp.erase(it);
        }
        else
            return false;
    }
    return true;
}
int main(){

}