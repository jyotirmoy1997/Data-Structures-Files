#include<bits/stdc++.h>
using namespace std;
class KthLargest {
    public:
        int k;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for (int num : nums) {
                add(num);
            }
        }

        int add(int val) {
            if (minHeap.size() < k) {
                minHeap.push(val);
            } else if (val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
            }
            return minHeap.top();
        }
};
int main(){
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;   // return 4
    cout << kthLargest.add(5) << endl;   // return 5
    cout << kthLargest.add(10) << endl;  // return 5
    cout << kthLargest.add(9) << endl;   // return 8
    cout << kthLargest.add(4) << endl;   // return 8
    return 0;
}