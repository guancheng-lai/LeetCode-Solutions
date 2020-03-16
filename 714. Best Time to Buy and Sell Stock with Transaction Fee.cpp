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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int buy = -prices[0]-fee;
		int sell = 0; //std::numeric_limits<int>::min();
		for (int i = 1, i2 = prices.size(); i < i2; ++i) {
			buy = max( buy,sell-prices[i]-fee );
			sell = max( sell,buy+prices[i] );
		}
				
		return sell;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> p{1,3,2,8,4,9};
	cout << s.maxProfit(p, 2);
}