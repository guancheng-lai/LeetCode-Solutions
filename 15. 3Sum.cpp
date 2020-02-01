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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector< vector<int> > result;
		if (nums.size() <= 2) return result;
		
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i) {
			if (i == 0 || nums[i] != nums[i - 1]) {
				int lo = i + 1, hi = nums.size() - 1, sum = 0 - nums[i];
				while (lo < hi) {
					if (nums[lo] + nums[hi] == sum) {
						vector<int> res{ nums[i], nums[lo], nums[hi] };
						result.push_back(res);
						
						while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
						while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
						lo++; hi--;
					}
					else if (nums[lo] + nums[hi] < sum) {
						lo++;
					}
					else {
						hi--;   
					}   
				}
			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> v{ -1, 0, 1, 2, -1, -4 };
	vector< vector<int> > result = s.threeSum(v);
	for (auto &v : result) {
		for (auto &i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}