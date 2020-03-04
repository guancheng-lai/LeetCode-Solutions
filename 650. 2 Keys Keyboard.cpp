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
	int minSteps(int n) {
		if (n == 1) return 0;
		if (n <= 5) return n;
		
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; ++i) {
			dp[i] = i;
		}
		
		
		for (int i = 1; i <= n; ++i) {
			for (int j = i + i; j <= n; j += i) {
				dp[j] = min(dp[j], dp[i] + j/i);
			}
		}
		
		return dp.back();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	for (int i = 1; i <= 1024; i *= 2)
		cout << i << " need " << s.minSteps(i) << " steps" << endl;
}