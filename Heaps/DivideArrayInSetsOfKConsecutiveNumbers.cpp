#include<bits/stdc++.h>
using namespace std;

// This is the Brute Force Approach
bool isPossibleDivide(vector<int>& nums, int k){
    if(nums.size() % k != 0)
        return false;

    set<int> st(nums.begin(), nums.end());
    unordered_map<int, int> mpp;
    for(auto it : nums)
        mpp[it]++;
    
    int total = 0;
    for(auto it : st){
        auto el = it;
        while(mpp[el] != 0){
            mpp[el]--;
            int count = 1;
            int current = el;
            for(int i=0; i<k-1; i++){
                if(mpp[current + 1] != 0){
                    mpp[current + 1]--;
                    current += 1;
                    count++;
                }
            }
            if(count == k)
                total++;
        }
    }
    cout << total;
    return (nums.size() / k == total) ? true : false;
}

// This is the Optimal Approach => Use a Min Heap
bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize != 0)
        return false;

    map<int, int> m;
    for (int i = 0; i < n; i++) 
        m[hand[i]]++;
    
    while (!m.empty()) {
        int curr = m.begin()->first; // Careful => begin() is a pointer and not an iterator. Thus we use -> operator
        for (int i = 0; i < groupSize; i++) {
            if (m[curr + i] == 0) {
                return false;
            }
            m[curr + i]--;
            if (m[curr + i] < 1) {
                m.erase(curr + i);
            }
        }
    }
    return true;
}
int main(){
    vector<int> nums = {3, 3, 2, 2, 1, 1};
    cout << isPossibleDivide(nums, 3);
}