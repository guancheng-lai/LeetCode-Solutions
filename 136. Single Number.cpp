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
	int singleNumber(vector<int>& nums) {
		int res(0);
		for (auto i : nums){
			res ^= i;
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{4,1,2,1,2,3,4};
	cout << s.singleNumber(arr);
}