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
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
		if (nums.size() <= 2) return result;
		
		int minDistance = std::numeric_limits<int>::max();
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i) {
			int lo = i + 1, hi = nums.size() - 1;
			int sum = target - nums[i];
            int currMinDistance = abs(sum - (nums[lo] + nums[hi]));
            while (lo < hi) {
				int thisDistance = abs(sum - (nums[lo] + nums[hi]));
				if ( thisDistance <= currMinDistance ) {
					currMinDistance = thisDistance;
					if (currMinDistance < minDistance) {
						result = nums[i] + nums[lo] + nums[hi];    
						minDistance = currMinDistance;
					}
					
					if ( abs( sum - (nums[lo] + nums[lo+1]) ) <  abs( sum - (nums[hi-1] + nums[hi]) ) ) {
						hi--; 
					}
					else {
						lo++;
					}
				}
				else if (nums[lo] + nums[hi] < sum) {
					lo++;
				}
				else {
					hi--;   
				}
			}
		}
		
		return result;

    }
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> v{ 0,2,1,-3 };
	cout << s.threeSumClosest(v, 1) << " == 0" << endl;
	vector<int> v2{ -1,2,1,-4 };
	cout << s.threeSumClosest(v2, 1) << " == 2" << endl;
}