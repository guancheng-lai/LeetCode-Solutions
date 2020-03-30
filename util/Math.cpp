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

int catalan(int n) {
	vector<int> dp(n+1);
	dp[0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = dp[j] * dp[i-j-1];
		}	
	}
	
	return dp[n];
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(int argc, char *argv[]) {
	
}