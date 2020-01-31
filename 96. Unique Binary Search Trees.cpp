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
public:
	int numTrees(int n) {
		if (n < 0) return 0;
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] += dp[j] * dp[i - j - 1];    
			}
		}
		
		return dp[n];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	for (int i = 0; i < 16; i++) {
		cout << i << " : " << s.numTrees(i) << endl;
	}
}