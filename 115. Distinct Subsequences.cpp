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

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const int mod = 1e9 + 7;
// const int mod = 998244353;

class Solution {
public:
	int numDistinct(string S, string T) {
		if (T.empty()) return 1;
		if (S.size() < T.size()) return 0;    
		
		size_t sLength = S.size(), tLength = T.size();
		vector< vector<LL> > dp(tLength+1, vector<LL>(sLength+1,0));
		for (int s = 0; s <= sLength; ++s) dp[0][s] = 1;
		
		for (int t = 1; t <= tLength; ++t) {
			for (int s = t; s <= sLength; ++s) {
				if (T.at(t-1) == S.at(s-1)) {
					// 
					dp[t][s] = dp[t][s-1] + dp[t-1][s-1];
				}
				else {
					// As before
					dp[t][s] = dp[t][s-1];
				}
			}
		}
		
		return (int) dp[tLength][sLength];
	}
};    


//              r   ra   rab   rabb   rabbb   rabbbi   rabbbit   <- S
//      r       0   1    1     1      1       1        1  
//      ra      0   1    1     1      1       1        1
//      rab     0        1     2      3       3        3
//      rabb    0              1      3       3        3
//      rabbi   0                     0       3        3
//      rabbit  0                             0        3  
//         T    0                                      

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.numDistinct("rabbbit", "rabbit");
}