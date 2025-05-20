/*
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.
*/

#include<iostream>
#include<sstream>
#include<climits>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<cassert>
using namespace std;

class AllOne {
	// Frequency of current strings
	unordered_map<string, int> string_freq;

	// set of all strings and their frequencies
	// {10, mostafa}, {15, ali}, etc
	set<pair<int, string> > freq_st;

	// Property: if tie, we return the smallest string

public:
	AllOne() {
	}

	void inc(string key) {	// O(logn)
		if (string_freq.count(key)) {	// exist
			int freq = string_freq[key];
			string_freq[key] = freq + 1;
			// remove old entry and add incremented one
			freq_st.erase({ freq, key });
			freq_st.insert( { freq + 1, key });
		} else {
			string_freq[key] = 1;
			freq_st.insert( { 1, key });
		}
	}
	void dec(string key) {	// O(logn)
		int freq = string_freq[key];
		freq_st.erase({ freq, key });

		if (freq > 1) {	// It will remain with us
			string_freq[key] = freq - 1;
			freq_st.insert( { freq - 1, key });
		} else
			string_freq.erase(key);
	}
string getMaxKey() {		// O(1)
		if (freq_st.empty())
			return "";
		return freq_st.rbegin()->second;
	}
	 

	string getMinKey() {		// O(1)
		if (freq_st.empty())
			return "";
		return freq_st.begin()->second;
	}
};

