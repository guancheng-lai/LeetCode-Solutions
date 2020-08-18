class Solution {
public:
	unordered_map<int,int> dp;
	
	int dfs(int n) {
		if (n <= 2) return n;
		if (dp.find(n) != dp.end()) return dp[n];
		
		int res2, res3;
		if (n % 2 == 1) res2 = dfs(n/2) + 2;
		if (n % 2 == 0) res2 = dfs(n/2) + 1;
		if (n % 3 == 2) res3 = dfs(n/3) + 3;
		if (n % 3 == 1) res3 = dfs(n/3) + 2;
		if (n % 3 == 0) res3 = dfs(n/3) + 1;
		
		dp[n] = res2 < res3 ? res2 : res3;
		return dp[n];
	}
	
	int minDays(int n) {
		return dfs(n);
	}
};

