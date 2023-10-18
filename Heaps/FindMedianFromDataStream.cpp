/* Approach => The Idea is to use two heaps, a Max Heap to store the elements lesser than
the median, and a Min Heap to store elements greater than the median. */

#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num)
            maxHeap.push(num);
        
        else
            minHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int size1 = maxHeap.size();
        int size2 = minHeap.size();
        double med;
        if(size1 > size2)
            med = maxHeap.top();
        
        else if(size1 < size2)
            med = minHeap.top();
        
        else if(size1 == size2){
            med = (maxHeap.top() + minHeap.top())/2;
        }
        return med;
    }
};
int main(){
    MedianFinder medianFinder;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    cout << medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    cout << medianFinder.findMedian(); // return 2.0
}