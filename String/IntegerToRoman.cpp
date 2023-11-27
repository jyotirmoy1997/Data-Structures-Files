#include<bits/stdc++.h>
using namespace std;
string intToRoman(int num){
    vector<pair<string, int>> table = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, 
                                       {"XL", 40} ,{"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, 
                                       {"D", 500}, {"CM", 900}, {"M", 1000}};

    string res = "";
    for(int i=12; i>=0; i--){
        int val = table[i].second;
        string sym = table[i].first;
        if(num / val > 0){
            int count = num/val;
            string s = "";
            for(int j=1; j<=count; j++)
                s += sym;
            
            res += s;
            num = num % val;
        }
    }
    return res;
}
int main(){
    int num = 1776;
    cout << intToRoman(num);
}