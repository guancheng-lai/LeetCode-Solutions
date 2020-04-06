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
	int lengthOfLIS(vector<int>& nums) {
//		if (nums.size() <= 1) return nums.size();
//				
//		vector< int > dp(nums.size(), 1);
//		dp[0] = 1;
//		int longest(1);
//		for (int i = 1; i < nums.size(); ++i) {
//			for (int j = 0; j < i; ++j) {
//				if (nums[i] > nums[j] && dp[j] >= dp[i]) {
//					dp[i] = dp[j] + 1;
//				}
//			}
//			
//			if (dp[i] > longest) {
//				longest = dp[i];
//			}
//		}
//		
//		return longest;
		
		vector<int> v;
		for (auto i : nums) {
			auto it = lower_bound(v.begin(), v.end(), i);
			if (it == v.end()) v.push_back(i);
			else *it = i;
			
			for (auto r : v) cout << r << " " ;
			
			cout << endl;
		}
		
		return v.size();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{10,9,2,5,3,6,7,101,18,102};
	cout << s.lengthOfLIS(arr);
}	