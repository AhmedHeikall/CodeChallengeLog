/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minAreaRect(vector<vector<int>> &points) {	// O(n^2)
		int minArea = INT_MAX;

		// Each entry is an x and all its ys
		// E.g. (2, 6), (2, 1), (2, 10) will be [2] : {6, 1, 10}
		unordered_map<int,unordered_set<int>> x_to_ys_table;
		int sz = points.size();

		for (int i = 0; i < sz; i++)	// add a y for this x
			x_to_ys_table[points[i][0]].insert(points[i][1]);

		for (int i = 0; i < sz; i++) {
			int x1 = points[i][0], y1 = points[i][1];

			for (int j = i + 1; j < sz; j++) {

				int x2 = points[j][0], y2 = points[j][1];

				if (x1 == x2 || y1 == y2)
					continue;	// same x-axis or y-axis

				if (!x_to_ys_table[x1].count(y2) || !x_to_ys_table[x2].count(y1))
					continue;	// One of the 2 other corners don't exist

				int area = abs(x2 - x1) * abs(y2 - y1);
				minArea = min(minArea, area);
			}
		}
		if (minArea == INT_MAX)
			minArea = 0;	// No valid 4 points

		return minArea;
	}
};

int main() {

	return 0;
}
