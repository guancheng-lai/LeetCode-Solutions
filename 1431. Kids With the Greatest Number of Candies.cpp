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
	vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
		vector<bool> res(candies.size());
		int maxC = *max_element(candies.begin(),candies.end());
		for (int i = 0; i < candies.size(); ++i) {
			if (candies[i] + extra >= maxC) {
				res[i] = true;
			}
			else {
				res[i] = false;
			}
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{ 2,3,5,1,3 };
	s.kidsWithCandies(arr, 3);
}