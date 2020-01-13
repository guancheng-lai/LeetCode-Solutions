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
private:
	void addToResult(vector<int> &result, int i, int j) {
		for (; i <= j; i++) {
			result.push_back(i);
		}
	}
	
	// template <typename T>
	// void printVector(const vector<T> &v) {
	//     cout << "\n-------------\nVECTOR: ";
	//     for (auto &i : v) {
	//         cout << i << " ";
	//     }
	//     cout << "\n-------------\n";
	// }

public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		if (nums.empty())
		{
			return nums;
		}
		
		std::sort(nums.begin(), nums.end());
		vector<int> result;
		int cur = 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == cur) {
				cur++;
			}
			else if (nums[i] > cur) {
				addToResult(result, cur, nums[i] - 1);
				cur = nums[i] + 1;
				
			}
		}
		
		// printVector(result);
		// cout << "Cur = " << cur << endl;
		addToResult(result, cur, nums.size());
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums{4,3,2,7,8,2,3,1};
	vector<int> correctOutput{5,6};
	
	vector<int> result = s.findDisappearedNumbers(nums);

	assert(result == correctOutput);
}