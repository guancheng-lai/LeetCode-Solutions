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
	int longestSubarray(vector<int>& nums, int limit) {
		int res = 0;
		int start = 0, end = 0;
		multiset<int> s;
		s.insert(nums[0]);
		
		while (start != nums.size()-1) {
			while (*s.rbegin() - *s.begin() <= limit && end < nums.size()-1) {
				res = max( res,end-start+1 );
				s.insert(nums[++end]);
			}
			
			while (!s.empty() && *s.rbegin() - *s.begin() > limit) {
				auto it = s.find(nums[start++]);
				s.erase(it);
			}
			
			if (end == nums.size()-1 && *s.rbegin() - *s.begin() <= limit) {
				break;
			}
			
			if (end < start) {
				end = start;
				s.clear();
			}
		}
		
		return max(res, end-start+1);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums{ 8,2,4,7 }; // 4
	cout << s.longestSubarray(nums, 4);	
}