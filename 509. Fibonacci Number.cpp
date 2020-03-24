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
	// Math Approach
	// 4ms 8.4MB
	// static constexpr double sqrt5 = 2.2360679775;
	// int fib(int N) {
	//     return (1.0 / sqrt5) * (pow(((1.0 + sqrt5) / 2.0), N) - pow(((1.0 - sqrt5) / 2.0), N));
	// }
	
	// Recursive Approach
	// 0ms 6.6MB
	// unordered_map<int,int> memo;
	// int fib(int N) {
	//     if (N <= 1) return N;
	//     if (memo.count(N)) return memo[N];
	//     int result = fib(N-1) + fib(N-2);
	//     memo[N] = result;
	//     return result;
	// }
	
	// Dynamic Programming Approach
	// 0ms 6.1MB
	int fib(int N) {
		if (N <= 1) return N;
		vector<int> dp(31,0); dp[1] = 1;
		
		for (int i = 2; i <= N; ++i) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		
		return dp[N];
	}
};
int main(int argc, char *argv[]) {
	Solution s;
	cout << s.fib(10);	
}