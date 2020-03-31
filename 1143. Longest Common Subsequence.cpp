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
	int longestCommonSubsequence(string text1, string text2) {
		size_t len1 = text1.size(), len2 = text2.size();
		vector< vector<int> > dp(len1+1, vector<int>(len2+1, 0));
		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j) {
				if (text1[i] == text2[j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
				}
				else {
					dp[i+1][j+1] = max( dp[i][j+1],dp[i+1][j] );
				}
			}
		}
		
		return dp[len1][len2];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout <<	s.longestCommonSubsequence("abcde", "ace");
}