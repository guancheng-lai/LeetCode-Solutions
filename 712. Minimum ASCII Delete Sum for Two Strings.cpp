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
	int minimumDeleteSum(string s1, string s2) {
		size_t len1 = s1.size(), len2 = s2.size();
		vector< vector<int> > dp(len1+1, vector<int>(len2+2, 0));
		dp[0][0] = 0;
		for (int i = 1; i <= len1; ++i) dp[i][0] = dp[i-1][0] + s1.at(i-1);
		for (int i = 1; i <= len2; ++i) dp[0][i] = dp[0][i-1] + s2.at(i-1);
		
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {
				if (s1.at(i-1) == s2.at(j-1)) {
					dp[i][j] = dp[i-1][j-1];
				}
				else {
					dp[i][j] = min( dp[i][j-1]+s2.at(j-1), dp[i-1][j]+s1.at(i-1) );
				}
			}
		}
		
		return dp[len1][len2];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.minimumDeleteSum("delete", "leet");	
}