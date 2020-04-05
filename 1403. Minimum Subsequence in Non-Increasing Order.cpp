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
	vector<int> minSubsequence(vector<int>& nums) {
		if(nums.size() == 1) return vector<int>{nums[0]};
		
		int sum(0);
		priority_queue<int> pq;
		for (auto i : nums) {
			pq.push(i);
			sum += i;
		}
		
		vector<int> res;
		int subSum(0);
		while (subSum <= sum) {
			int t = pq.top(); pq.pop();
			subSum += t;
			sum -= t;
			res.push_back(t);
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{4,3,10,9,8};
	auto v = s.minSubsequence(arr);	
	for (int i : v) cout << i << " ";
}