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
		vector<int> exist(nums.size() + 1, 0);
		for (auto &i : nums) {
			exist[i] = 1;
		}
		
		vector<int> result;
		for (int i = 1; i < exist.size(); ++i) {
			if (exist[i] == 0) {
				result.push_back(i);
			}
		}
		
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