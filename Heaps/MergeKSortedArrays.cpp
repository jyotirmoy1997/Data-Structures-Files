/* Approach => The Idea is to use a min heap to store the min element
at each iteration. */

#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKArrays(vector<vector<int> > arr)
{
	vector<int> output;
	priority_queue<pair<int, pair<int, int>>, 
    vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // First Push all the 0th element of all arrays into the min heap.
	for (int i = 0; i < arr.size(); i++)
		pq.push({ arr[i][0], { i, 0 } });

    // Iterate over the queue to find the next smaller element
	while (pq.empty() == false) {
		auto curr = pq.top();
		pq.pop();

		int i = curr.second.first;
		int j = curr.second.second;

		output.push_back(curr.first);

		if (j + 1 < arr[i].size())
			pq.push({ arr[i][j + 1], { i, j + 1 } });
	}

	return output;
}

int main()
{
	vector<vector<int> > arr{ { 2, 6, 12 },
							{ 1, 9 },
							{ 23, 34, 90, 2000 } };

	vector<int> output = mergeKArrays(arr);

	cout << "Merged array is " << endl;
	for (auto x : output)
		cout << x << " ";

	return 0;
}
