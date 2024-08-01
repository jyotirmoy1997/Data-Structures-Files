#include<bits/stdc++.h>
using namespace std;
int countSeniors(vector<string>& details){
    int count = 0;
    for(auto it : details){
        int age = stoi(it.substr(11, 2));
        if(age > 60)
            count++;
    }
    return count;  
}
int main(){
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout << countSeniors(details);
}   