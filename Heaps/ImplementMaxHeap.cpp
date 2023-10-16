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
int main(){
    vector<int> arr = {5, 7, 1, 8, 2, 10, 2, 21, 4};
    int n = arr.size();
    for(int i=(n/2) - 1; i>= 0; i--)
        heapify(arr, n, i);

    for(auto it : arr)
        cout << it << " ";
}