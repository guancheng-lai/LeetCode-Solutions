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
	constexpr static int MOD = 1000000007;
	int knightDialer(int N) {
		if (N == 1) return 10;
		
		vector<int> prev(10,1), curr(10, 0);
		while (N-- != 1) {
			curr[0] = (prev[4] + prev[6]) % MOD;
			curr[1] = (prev[6] + prev[8]) % MOD;
			curr[2] = (prev[7] + prev[9]) % MOD;
			curr[3] = (prev[4] + prev[8]) % MOD;
			curr[4] = ( (prev[0] + prev[3]) % MOD + prev[9]) % MOD;
			curr[6] = ( (prev[0] + prev[1]) % MOD + prev[7]) % MOD;
			curr[7] = (prev[2] + prev[6]) % MOD;
			curr[8] = (prev[1] + prev[3]) % MOD;
			curr[9] = (prev[2] + prev[4]) % MOD;
			prev = curr;
		}
		
		return accumulate(prev.begin(), prev.end(), 0, [](const int a, const int b) {
			return (a%MOD + b%MOD)%MOD;
		});
	}
};

int main(int argc, char *argv[]) {
	Solution s;	
	cout << s.knightDialer(3);
}