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
	int longestConsecutive(vector<int>& nums) 
	{
		unordered_set<int> s(nums.begin(), nums.end());

		int longest(0);
		for (auto i : s) {
			if (s.count(i-1) == 0) {
				int i2 = i + 1;
				while (s.count(i2) != 0) i2++;
				longest = (i2 - i > longest) ? i2 - i : longest;
			}
		}
		
		return longest;
		
		/*
		Sort Approach
		if (nums.empty()) return 0;
		
		std::sort(nums.begin(), nums.end());
		int longest(1);
		int cur(1);
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] + 1 == nums[i + 1])
			{
				++cur;
			}
			else if (nums[i] == nums[i + 1])
			{
				 
			}
			else
			{
				if (longest < cur)
				{
					longest = cur;
				}
				
				cur = 1;
			}
		}
		
		if (longest < cur)
		{
			longest = cur;
		}
		
		return longest;
		*/
	}
};

int main(int argc, char *argv[]) {
	vector<int> arr { 100, 4, 200, 1, 3, 2 };
	Solution s;
	assert(s.longestConsecutive(arr) == 4);
}