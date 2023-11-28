#include<bits/stdc++.h>
using namespace std;
void rabinKarpAlgo(string txt, string pat, int q){
    int M = pat.length();
    int N = txt.length();
    int p = 0, t = 0, h = 1, d = 256;

    // Step 1 : Calculate the maximum value of Power
    for(int i=0; i<M-1; i++)
        h = (h * d) % q;

    /* Step 2 : Calculate the hash value of the pattern as well as the first hash
                value of txt 
    */ 
    for(int i=0; i<M; i++){
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    /* Apply the sliding window method to calculate the next hash value and
       compare the hash value */
    for(int i=0; i<=N-M; i++){
        // If pattern's hash value and text's hash value is the same, then we perform char by char comparison
        if(p == t){
            int j = 0;
            while(j < M){
                if(txt[i+j] != pat[j])
                    break;
                j++;
            }
            // If all of the pattern is matched, we print the index
            if(j == M)
                cout << "Pattern Found at Location :: " << i << endl; 
        }
        if(i < N-M){
            // Perform Rolling hash 
            t = ((d * (t - h * txt[i])) + txt[i+M]) % q;
            if(t < 0)
                t += q;
        }
    }
}
int main(){
    string txt = "aaababa";
    string pattern = "aba";
    int q = INT_MAX;
    rabinKarpAlgo(txt, pattern, q);
}