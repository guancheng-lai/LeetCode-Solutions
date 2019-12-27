#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
#include <memory>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		size_t half = nums.size() / 2;
		
		/*
		// nth_element 24ms 11.2MB
		std::nth_element(nums.begin(), nums.begin() + half, nums.end());
		return nums[half];
		*/
		
		/*
		// Hash table 16ms 11.2MB
		unordered_map<int, int> m;
		for (auto &i : nums) {
			m[i]++;
		}
		
		for (auto &[k,v] : m) {
			if (v > half) {
				return k;
			}
		}
		return 0;
		*/
		
		// Boyer-Moore 20ms 10.9MB
		int major = nums[0], count = 1;
		for (int i = 1, end = nums.size(); i < end; ++i) {
			if (count == 0) {
				major = nums[i];
				count = 1;
			}
			else if (major == nums[i]) {
				count++;
			}
			else {
				count--;
			}
		}
		return major;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums { 2,2,1,1,1,2,2 };
	cout << s.majorityElement(nums) << " should equal to 2\n";
}