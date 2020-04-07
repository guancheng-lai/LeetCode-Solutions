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
	int findNumberOfLIS(vector<int>& nums) {
		size_t n = nums.size();
		if (n <= 1) return nums.size();
		
		vector<int> dp(n,1), cnt(n,1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]){
					if (dp[j] >= dp[i]) {  
						dp[i] = dp[j] + 1;
						cnt[i] = cnt[j];
					}
					else if(dp[j] + 1== dp[i]) {
						cnt[i] += cnt[j];
					}
				}
			}
		}
		
		int res = 0, maxLength = *max_element(dp.begin(), dp.end());
		for (int i = 0; i < n; ++i) {
			if (dp[i] == maxLength) {
				res += cnt[i];
			}
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	vector<int> arr{1,3,5,4,7};
	vector<int> arr{2,2,2,2,2};
	cout << s.findNumberOfLIS(arr);	
}