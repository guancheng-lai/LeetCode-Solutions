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
	int longestArithSeqLength(vector<int>& A) {
		vector< vector<int> > dp(A.size()+1, vector<int>(20000, 0));
	
		int longest = 0;
		for (int i = 0; i < A.size(); ++i) {
		    for (int j = 0; j < i; ++j) {
		int diff = A[i] - A[j];
		if (diff < 0) diff = abs(diff) + 10000;
		dp[i][diff] = dp[j][diff] + 1;
		longest = max(longest,dp[i][diff]);
	    }
	}
	
	return longest+1;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{20,1,15,3,10,5,8};
	s.longestArithSeqLength(A);
}