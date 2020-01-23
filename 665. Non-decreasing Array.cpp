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
private:
	bool absoluteCheck(vector<int>& nums) {
		for (int i = 0, end = nums.size() - 1; i < end; ++i) {
			if (nums[i] > nums[i+1]) return false;
		}
		
		return true;
	}
	
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() <= 1) return true;
		
		for (int i = 0, end = nums.size() - 1; i < end; ++i) {
			if (nums[i] > nums[i + 1]) {             
					
				int preserve = nums[i];
				nums[i] = nums[i + 1];
				
				bool prev = absoluteCheck(nums);
				nums[i] = preserve;
				 
				bool next = false;
				nums[i + 1] = nums[i];
				next = absoluteCheck(nums);
			
				return (prev || next);
			}
		}
		
		return true;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> v{ 3,4,2,3 };
	assert(!s.checkPossibility(v));
	
	vector<int> v2{ 4,2,3 };
	assert(s.checkPossibility(v2));
}