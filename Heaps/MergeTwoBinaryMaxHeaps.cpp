#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
vector<int> mergeheaps(vector<int> &heap1, vector<int> &heap2){
    vector<int> mergedHeap(heap1.begin(), heap1.end());
    for(auto it : heap2)
        mergedHeap.push_back(it);

    int n = mergedHeap.size();
    for(int i=(n/2)-1; i>=0; i--){
        heapify(mergedHeap, n, i);
    }
    return mergedHeap;
}
int main()
{
    vector<int> heap1 = {10, 9, 8, 7, 6, 5};
    vector<int> heap2 = {13, 11, 12, 3, 4};
    auto res = mergeheaps(heap1, heap2);

    for(auto it : res)
        cout << it << " ";
}