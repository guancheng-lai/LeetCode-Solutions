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
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		size_t len = nums.size();
		if (len == 0) return vector<int>();
		if (k == len) return vector<int>(len-k+1, *max_element(nums.begin(), nums.end()));
		
		vector<int> result; // Elements inside it
		deque<int> deq; // Indexes inside it
		
		for (int i = 0; i < len; ++i) 
        {
			while (!deq.empty() && deq.back() < i-k+1) 
            {
                deq.pop_back();    
            }
			
			while (!deq.empty() && nums[deq.front()] < nums[i]) 
            {
                deq.pop_front();
            }
			
			deq.push_front( i );
			
            if (i >= k-1) result.push_back( nums[deq.back()] );
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	vector<int> nums{ 1,3,-1,-3,5,3,6,7 }; // 3
	vector<int> nums{ 5,3,4 }; // 1
	vector<int> res = s.maxSlidingWindow(nums, 1);	
	for (auto i : res) cout << i << " ";
}