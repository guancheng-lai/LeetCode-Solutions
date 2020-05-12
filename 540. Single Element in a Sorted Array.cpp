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
	int singleNonDuplicate(vector<int>& nums)
	{
		if (nums.size() < 1) return 0;
		if (nums.size() == 1) return nums[0];
		
		int N = nums.size();
		int left = 0, right = N-1;
		while (left <= right)
		{
            if (left == right) return nums[left];
			
            int mid = left + (right-left)/2;
			if (mid % 2 == 1) mid--;
            
			if (mid != N-1 && nums[mid] == nums[mid+1])
			{
				left = mid + 2;
			}
			else if (mid != 0 && nums[mid] == nums[mid-1])
			{
				right = mid - 2;
			}
			else 
			{
				return nums[mid];	
			}
		}
		
		return nums[left];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	vector<int> nums{1,1,2,3,3,4,4,8,8};
//	vector<int> nums{1,1,2,2,3,3,4,4,8,8,9};
//	vector<int> nums{1,1,2};
//	vector<int> nums{2,3,3};
	vector<int> nums{ 1,2,2,3,3 };
	int res = s.singleNonDuplicate(nums);	
	cout << res;
}