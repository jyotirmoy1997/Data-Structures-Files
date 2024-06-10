#include<bits/stdc++.h>
using namespace std;
int heightChecker(vector<int>& heights) {
    vector<int> expected(heights.begin(), heights.end());
    sort(expected.begin(), expected.end());
    int count = 0, n = heights.size();
    for(int i=0; i<n; i++){
        if(heights[i] != expected[i])
            count++;
    }
    return count;
}
int main(){
    vector<int> heights = {1,1,4,2,1,3};
    cout << heightChecker(heights);
}