#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int>& fruits){
    unordered_map<int, int> mpp;
    int left = 0, right = 0, n = fruits.size(), maxLen = 0;
    while(right < n){
        mpp[fruits[right]]++;

        while(mpp[fruits[left]] > 0 && mpp.size() > 2){
            mpp[fruits[left]]--;
            if(mpp[fruits[left]] == 0)
                mpp.erase(fruits[left]);

            left++;
        }
        // cout << mpp.size();
        if(mpp.size() == 2){
            // cout << "Reach";
            maxLen = max(maxLen, right - left + 1);
        }
            

        right++;
    }
    return maxLen;
}
int main(){
    // vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << totalFruit(fruits);
}