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
	bool kLengthApart(vector<int>& nums, int k) {
		if (k == 0) return true;
	   
		int curr = distance(nums.begin(), find(nums.begin(), nums.end(), 1));
		for (int i = curr+1; i < nums.size(); ++i) {
			if (nums[i] != 1) continue;
			if (i - curr < k+1) return false;
			
			curr = i;
		}
		
		return true;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums{ 1,0,0,0,1,0,0,1 }; // 2
	assert(s.kLengthApart(nums, 2) == true);	
}