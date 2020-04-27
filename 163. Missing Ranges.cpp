#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string_view>
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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		if (nums.size() == 0) {
			if (lower == upper) result.push_back(to_string(lower));
			else result.push_back(to_string( lower ) + "->" + to_string( upper ));
			
			return result;
		}
		
		
		if (lower < nums[0]) {
			if (lower+1 == nums[0]) {
				result.push_back(to_string(lower));
			}
			else {
				result.push_back(to_string(lower) + "->" + to_string(nums[0]-1));    
			}
			
		}
		
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i-1] == nums[i]) continue;
			if (nums[i-1]+1 != nums[i]) {
				if (nums[i-1]+2 == nums[i]) {
					result.push_back(to_string(nums[i-1]+1));
				}
				else {
					result.push_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));    
				}
			}
		}
		
		if (nums.back() < upper) {
			if (nums.back()+1 == upper) {
				result.push_back(to_string( nums.back()+1 ));
			}
			else {
				result.push_back(to_string(nums.back()+1) + "->" + to_string(upper));    
			}
			
		}
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{1,2,3};
	vector<string> res = s.findMissingRanges(arr, 1, 5);
	for (auto &s : res) cout << s << " ";
}