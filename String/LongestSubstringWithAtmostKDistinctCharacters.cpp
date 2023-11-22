#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str){
    unordered_map<char, int> mpp;
    int right = 0, left = 0, len = str.length(), maxLen = 0;
    while(right < len){
        mpp[str[right]]++;

        while(mpp.size() > k && mpp[str[left]] > 1){
            mpp[str[left]]--;
            if(mpp[str[left]] == 0)
                mpp.erase(str[left]);

            left++;
        }

        if(mpp.size() == k)
            maxLen = max(maxLen, right - left + 1);
        
        right++;
    }
    return maxLen;
}
int main(){

}