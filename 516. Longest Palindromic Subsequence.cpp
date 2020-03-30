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
	int longestPalindromeSubseq(string s) {
		size_t n = s.size();
		vector< vector<int> > dp(n+1, vector<int>(n+1, 0));
		for (int len = 1; len <= s.size(); ++len){
			for (int i = 0; i + len <= s.size(); ++i) {
				if ( s[i] == s[i + len - 1] ) {
					dp[i][i + len] = dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2);
				}
				else {
					dp[i][i + len] = max(dp[i][i + len - 1], dp[i + 1][i + len]);
				}
			}
		}
		return dp[0][s.size()];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.longestPalindromeSubseq("bbbab");	
}