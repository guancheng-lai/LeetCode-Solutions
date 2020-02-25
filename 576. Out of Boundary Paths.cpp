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
using namespace std;

class Solution {
private:
	int numRows;
	int numCols;
	int result;
	const int MOD = 1000000007;
	vector< vector< vector<int>>> dp;
	
	void dfs(int step, int i, int j) {
		if (step < 0) return;
		if (i < 0 || j < 0 || i >= numRows || j >= numCols) { (this->result)++; return;  }
		if (dp[i][j][step] >= 0) { (this->result) = (this->result) % MOD + (dp[i][j][step] % MOD); return; }
		
		dp[i][j][step] = 0;
		int numPaths = this->result;
		dfs(step-1, i+1, j);
		dfs(step-1, i-1, j);
		dfs(step-1, i, j+1);
		dfs(step-1, i, j-1);
		dp[i][j][step] = this->result - numPaths;
	}
	
public:
	int findPaths(int m, int n, int N, int i, int j) {
		if (m <= 0 || n <= 0 || N <= 0 || i < 0 || j < 0) return 0;
		
		this->numRows = m;
		this->numCols = n;
		this->result = 0;
		(this->dp).resize(m+1, vector< vector<int>>(n+1, vector<int>(N+1, -1)));
		dfs(N, i, j);
		
		return this->result % MOD;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	assert( s.findPaths(45, 35, 47, 20, 31) == 951853874);
}