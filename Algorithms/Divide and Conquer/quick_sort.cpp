#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

int make_pivot(vector<int> &vec, int start, int end) {
	int mid = start + (end - start) / 2;
	int pivot = vec[mid];	

	int count = 0;
	for (int i = start; i <= end; i++)
		if (vec[i] < pivot)
			count += 1;

	int pivot_idx = start + count;
	swap(vec[pivot_idx], vec[mid]);

	for (int s = start, e = end; s < pivot_idx && e > pivot_idx; s += 1, e -= 1) {
		while (vec[s] < pivot)	// Find first value > pivot
			s += 1;		// tip loop must break worst at pivot_idx

		while (vec[e] > pivot)	// Find last value <= pivot
			e -= 1;

		if (s < pivot_idx && e > pivot_idx)
			swap(vec[s], vec[e]);
	}
	return pivot_idx;
}

void quicksort(vector<int> &vec, int start, int end) {
	if (start >= end)
		return;

	int pivot_idx = make_pivot(vec, start, end);
	quicksort(vec, start, pivot_idx - 1);
	quicksort(vec, pivot_idx + 1, end);
}

void quicksort(vector<int> &vec) {
	quicksort(vec, 0, (int) vec.size() - 1);
}

int main() {
	// no duplicate
	vector<int> vec { 12, 35, 87, 26, 9, 28, 7 };

	quicksort(vec); 
	for (int i = 0; i < (int) vec.size(); ++i)
		cout << vec[i] << " ";

	// 7 9 12 26 28 35 87

	return 0;
}
