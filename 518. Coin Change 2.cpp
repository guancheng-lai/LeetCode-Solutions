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
using namespace std;

class Solution {
public:   
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (auto coin : coins) {
			for (int i = coin; i <= amount; ++i) {
				dp[i] += dp[i - coin];
			}
		}
		
		return dp.back();
	}
};

int main(int argc, char *argv[]) {
	int amount = 5;
	vector<int> coins {1,2,5};
	Solution s;
	cout << s.change(5, coins);	
}