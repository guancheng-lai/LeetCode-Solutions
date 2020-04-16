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
	bool checkValidString(string s) {
		int pmin = 0, pmax = 0;
		for (auto &c : s) {
			switch (c) {
				case '(':
					pmin++;
					pmax++;
					break;
				case ')':
					pmax--;
					pmin--;
					if (pmin < 0) pmin = 0;
					break;
				case '*':
					pmax++;
					pmin--;
					if (pmin < 0) pmin = 0;
					break;
				default:
					return false;
			}
			
			if (pmax < 0) return false;
		}
		
		return pmin == 0;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	assert(s.checkValidString("(*()"));
}