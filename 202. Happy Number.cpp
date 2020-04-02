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
private:
	unordered_set<int> exist;
public:
	bool isHappy(int n) {
		if (exist.count(n)) return false;
		exist.insert(n);
		
		int sum(0);
		while (n != 0) {
			int digit = n % 10;
			sum += (digit*digit);
			n /= 10;
		}
		
		return ((sum == 1) ? true : isHappy(sum));
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	assert(s.isHappy(19));
}