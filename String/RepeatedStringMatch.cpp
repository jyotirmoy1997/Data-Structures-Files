/* This is an Implementation problem of the Rabin karp Algorithm */
#include<bits/stdc++.h>
using namespace std;
bool stringMatch(string txt, string pat, int q){
    int M = pat.length();
    int N = txt.length();
    int p = 0, t = 0, h = 1, d = 29;

    for(int i=0; i<M-1; i++)
        h = (long long)(h * d) % q;
 
    for(int i=0; i<M; i++){
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for(int i=0; i<=N-M; i++){
        if(p == t){
            int j = 0;
            while(j < M){
                if(txt[i+j] != pat[j])
                    break;
                j++;
            }
            if(j == M)
                return true; 
        }
        if(i < N-M){
            t = ((d * (t - h * txt[i])) + txt[i+M]) % q;
            if(t < 0)
                t += q;
        }
    }
    return false;
}
int repeatedStringMatch(string a, string b) {
    int q = INT_MAX;
    int required=ceil(b.size()/(double)a.size());
    string s="";
    for(int i=0;i<required;i++)
    {
        s += a;
    }
    if(stringMatch(s, b, q)) 
        return required;

    s+=a;
    if(stringMatch(s, b, q)) 
        return required+1;
    return -1;
}
int main(){
    string txt = "aaababa";
    string pattern = "aba";
    
}