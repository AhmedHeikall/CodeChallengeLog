// https://leetcode.com/problems/powx-n/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

/*

Simple idea
If we have a = 3^5, then 3^10 = a*a  and 3^11 = a*a*3

So divide the power to n/2
Compute the answer
Square it
If n was odd, multiply with extra x

 */

class Solution {
public:
	double fastPow(double x, long long n) {		// log(n)
		if (n == 0)
			return 1.0;

		double result = fastPow(x, n / 2);

		result *= result;
		if (n % 2 != 0)
			result *= x;

		return result;
	}
	double myPow(double x, int n) {
		long long N = n;
		if (N < 0) {
			x = 1 / x;
			N = -N;	// -MAX_INT overflows.
		}
		return fastPow(x, N);
	}
};

int main() {


	return 0;
}
