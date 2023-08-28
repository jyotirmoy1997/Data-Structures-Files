// Merging two sorted arrays with O(1)
// extra space
#include <bits/stdc++.h>
using namespace std;

// Function to find next gap.
int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

// This Approach uses the gap Method
void merge(int* arr1, int* arr2, int n, int m)
{
	int i, j, gap = n + m;
	for (gap = nextGap(gap);
		gap > 0; gap = nextGap(gap))
	{
		// comparing elements in the first array.
		for (i = 0; i + gap < n; i++)
			if (arr1[i] > arr1[i + gap])
				swap(arr1[i], arr1[i + gap]);

		// comparing elements in both arrays.
        int k =(gap > n) ? gap - n : 0;
		for (j = k; i < n && j < m; i++, j++)
			if (arr1[i] > arr2[j])
				swap(arr1[i], arr2[j]);

		if (j < m) {
			// comparing elements in the second array.
			for (j = 0; j + gap < m; j++)
				if (arr2[j] > arr2[j + gap])
					swap(arr2[j], arr2[j + gap]);
		}
	}
}

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2){
	int n = arr1.size();
	int m = arr2.size();
	int left = n - 1;
	int right = 0;
	while(right < m && left >= 0){
		if(arr1[left] > arr2[right]){
			swap(arr1[left], arr2[right]);
			left--;
			right++;
		}
		else
			break;
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
}
int main()
{
	vector<int> a1 = { 1, 5, 7, 11, 18};
	vector<int> a2 = {2, 6, 9, 12};
	// Function Call
	// merge(a1, a2, n, m);
	mergeSortedArrays(a1, a2);

	printf("First Array: ");
	for (int i = 0; i < a1.size(); i++)
		printf("%d ", a1[i]);

	printf("\nSecond Array: ");
	for (int i = 0; i < a2.size(); i++)
		printf("%d ", a2[i]);
	printf("\n");
	return 0;
}
