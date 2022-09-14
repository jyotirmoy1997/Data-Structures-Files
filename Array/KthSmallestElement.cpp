#include <bits/stdc++.h>
using namespace std;
void kLargestElement(int arr[], int k)
{
	priority_queue<int> pq;
	for(int i=0; i<k; i++)
	{
		pq.push(arr[i]);
	}
	for(int i=k; i<6; i++)
	{
		if(arr[i] < pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
	cout << pq.top();
}
int main() {
	int arr[] = {3, 1, 5, 12, 2, 11};
	kLargestElement(arr, 3);
	return 0;
}