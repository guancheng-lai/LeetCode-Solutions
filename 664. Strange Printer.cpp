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
	int strangePrinter(string s) {
		if (s.size() <= 1) return s.size();
		string s2("");
		for (auto c : s) 
			if (c != s2.back()) s2 += c;
		
		
		int n = s2.size();
		vector< vector<int> > dp(n, vector<int>(n, 1));
		
		for (int len = 1; len <= n; ++len) {
			for (int left = 0; left < n - len + 1; ++left) {
				int right = left + len - 1;
				dp[left][right] = len;
				for (int mid = left; mid < right; ++mid) {
					if (s2.at(mid) == s2.at(right)) {
						//dp[left][right] = std::min(dp[left][right], dp[left][mid] + dp[mid+1][right] - 1);
						int concat = dp[left][mid] + dp[mid+1][right] - 1;
						if (concat < dp[left][right]) dp[left][right] = concat;
						
					}
					else {
						// dp[left][right] = std::min(dp[left][right], dp[left][mid] + dp[mid+1][right]);
						int concat = dp[left][mid] + dp[mid+1][right];
						if (concat < dp[left][right]) dp[left][right] = concat;
					}
				}
			}
		}
		
		return dp[0].back();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.strangePrinter("aaabbbcccbbb") << endl;
	cout << s.strangePrinter("aaabbbcccddd") << endl;
}