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
	int maxProfit(vector<int>& prices) {
		int result(0);
		for (int i = 1, i2 = prices.size(); i < i2; ++i) {
			if (prices[i] > prices[i-1]) {
				result += (prices[i]-prices[i-1]);
			}
		}
		return result;
	}
};

int main(int argc, char *argv[]) {
	vector<int> v{ 7,1,5,3,6,4 };
	Solution s;
	cout << s.maxProfit(v);	
}