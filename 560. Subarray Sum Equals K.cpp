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
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		m[0] = 1;
		int result(0), sum(0);
		
		for (auto i : nums) {
			sum += i;
			if (m.find(sum-k) != m.end()) {
				result += m[sum-k];
			}
			
			m[sum]++;
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums{1,1,1};
	cout << s.subarraySum(nums, 2);	
}