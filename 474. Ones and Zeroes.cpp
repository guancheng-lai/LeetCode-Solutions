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
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (strs.size() == 0 || (m <= 0 && n <= 0)) return 0;
		vector< vector<int> > dp(m+1, vector<int>(n+1, 0));
		
		for (auto &&s : strs) {
			int numZeros(0), numOnes(0);
			for (auto c : s) {
				if (c == '0') ++numZeros;
				else if (c == '1') ++numOnes;
			}
			
			for (int r = m; r >= numZeros; --r) {
				for (int c = n; c >= numOnes; --c) {
					if ( dp[r-numZeros][c-numOnes]+1 > dp[r][c]) {
						dp[r][c] = dp[r-numZeros][c-numOnes]+1;
					}
				}
			}
		}
		
		return dp.back().back();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<string> v{"10", "0001", "111001", "1", "0"};
	cout << s.findMaxForm(v, 5, 3) << " == 4";
}