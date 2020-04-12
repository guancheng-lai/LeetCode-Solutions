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

// Pattern 121 -> 212,213,232,313,312
// Pattern 123 -> 212,231,232,312

class Solution {
public:
	const int MOD = 1e9 + 7;
	
	int numOfWays(int n) {
		int a121 = 6, a123 = 6;
		int b121, b123;
		for (int i = 2; i <= n; ++i) {
			b121 = (((a121 + a121)%MOD + a121)%MOD + (a123 + a123)%MOD) % MOD;
			b123 = ((a121 + a121)%MOD + (a123 + a123)%MOD) % MOD;
			a121 = b121;
			a123 = b123;
		}
		
		return (a121%MOD + a123%MOD) % MOD;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.numOfWays(3);	
}