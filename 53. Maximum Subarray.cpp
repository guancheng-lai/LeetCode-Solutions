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
	int maxSubArray(vector<int>& nums) {
		int sum(0);
		int maxSum(std::numeric_limits<int>::min());
		
		for (int i = 0, i2 = nums.size(); i < i2; ++i) {
			sum += nums[i];
			cout << sum << " ";
			
			if (sum > maxSum) maxSum = sum;
			if (sum < 0) sum = 0;
		}
		
		return maxSum;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
	vector<int> v{-2,-3,4,-1,-2,1,5,-3};
	int res = s.maxSubArray(v);	
	cout << endl << "Result = " << res << endl;
}