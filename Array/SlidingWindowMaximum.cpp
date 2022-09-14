#include <bits/stdc++.h>
using namespace std;
void printKMax(int arr[], int N, int K)
{
	deque<int> q(K);
	int i;
	for (i = 0; i < K; ++i) {
		while ((!q.empty()) && arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
		q.push_back(i);
	}
	for (; i < N; ++i) {
		cout << arr[q.front()] << " ";
		while ((!q.empty()) && q.front() <= i - K)
        {
            q.pop_front();
        }
		while ((!q.empty()) && arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
		q.push_back(i);
	}
	cout << arr[q.front()];
}

int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;
	printKMax(arr, N, K);
	return 0;
}
