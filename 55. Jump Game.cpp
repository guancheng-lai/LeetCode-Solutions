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
	bool canJump(vector<int>& nums) {
		int curr = 0;
		int maxJump = nums[curr];
		int nextJump = 0;
		for (int i=0; i<=maxJump && i<nums.size(); ++i) {
			nextJump = max( nextJump,i+nums[i] );
			maxJump = nextJump;
		}
		
		return maxJump >= nums.size()-1;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{ 3,2,1,0,4 };
	assert(s.canJump(A) == false);
	vector<int> B{ 2,3,1,1,4 };
	assert(s.canJump(B) == true);
}