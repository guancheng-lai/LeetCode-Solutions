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

namespace hashing {
	struct hash_pair { 
		template <class T1, class T2> 
		size_t operator()(const pair<T1, T2>& p) const
		{ 
			auto hash1 = hash<T1>{}(p.first); 
			auto hash2 = hash<T2>{}(p.second); 
			return hash1 ^ hash2; 
		} 
	}; 
}

class Solution {
private:
	unordered_map< pair<int,int>,int,hashing::hash_pair > memo;
	
	int dfs(vector<int>& nums, int left, int right) {
		if (left > right) return 0;
		if ( memo.find({left,right}) != memo.end() ) return memo[{left,right}];
		
		int maxPoints(0);
		for (int i = left; i <= right; ++i) {
			int points = nums[left-1] * nums[i] * nums[right+1]
				+ dfs(nums, left, i-1) 
				+ dfs(nums, i+1, right);
			
			if (points > maxPoints) maxPoints = points;
		}
		
		// cout << "left=" << left << ",right=" << right << ",res=" << maxPoints << endl;
		memo[{left,right}] = maxPoints;
		return maxPoints;
	}
	
public:
	int maxCoins(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		nums.insert( nums.begin(),1 ) ;
		nums.push_back(1);
		return dfs( nums,1,nums.size()-2 );
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> balloon{3,1,5,8};
	cout << s.maxCoins(balloon);
}