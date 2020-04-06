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

class Solution 
{
public:
	void moveZeroes(vector<int>& nums)
	{
		size_t len = nums.size();
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 0) 
			{
				nums.erase(nums.begin()+i);
				i--;
			}
		}
		
		nums.resize(len, 0);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums{0,1,0,3,12}; 
	s.moveZeroes( nums );
	for (int i : nums) cout << i << " " ;	
}