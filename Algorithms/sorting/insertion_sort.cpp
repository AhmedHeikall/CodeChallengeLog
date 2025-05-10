#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &nums) {
	// For each number: add it in the previous sorted subarray
	for (int i = 1; i < (int) nums.size(); i++) {
		int key = nums[i];
		int j = i - 1;
		// Shift and add in the right location
		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];	// shift right
			j--;
		}
		nums[j + 1] = key;	// The first right element
	}
}

vector<int> read_vector() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	return v; 
}

int main() {
	vector<int> v = read_vector();
	insertion_sort(v);

	for (int i = 0; i < (int) v.size(); ++i) {
		cout << v[i] << " ";
	}

	return 0;
}

