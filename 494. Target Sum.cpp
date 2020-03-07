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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
public:
	int S;
	vector< vector<int> > dp;
	
	int dfs(const vector<int> &nums, int idx, int currSum) {
		if (idx == nums.size()) {
			if (this->S == currSum) return 1;
			else return 0;
		}
				
		if (dp[idx][currSum+1000] != -1) { return dp[idx][currSum+1000]; }
		
		int currRes = dfs(nums, idx+1, currSum + nums[idx]) + dfs(nums, idx+1, currSum - nums[idx]);
		dp[idx][currSum+1000] = currRes;
		return currRes;
	}
	
	int findTargetSumWays(vector<int>& nums, int S) {
		if (S > 1000) return 0;
		
		this->S = S;
		this->dp.resize( nums.size(), vector<int>(2001,-1) );
		return dfs(nums, 0, 0);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums{1,1,1,1,1};
	cout << s.findTargetSumWays(nums, 3);
}