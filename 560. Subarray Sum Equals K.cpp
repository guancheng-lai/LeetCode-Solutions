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
	unordered_map<int, int> m;
	
public:
	int subarraySum(vector<int>& nums, int k) {
		int result = 0;
		int sum = 0;
		m[0] = 1;
		
		for (int i = 0, end = nums.size(); i < end; ++i) {
			sum += nums[i];
			if (m.find ( sum - k ) != m.end()) {
				result += m[sum - k];
			}
			
			m[sum]++;
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> v{ 1,1,1 };
	assert(s.subarraySum(v, 2) == 2);
}