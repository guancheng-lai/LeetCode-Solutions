class Solution {
public:
	int connectTwoGroups(vector<vector<int>>& cost) {
		int sz1 = cost.size(), sz2 = cost[0].size(), total = 1 << sz2;
		vector<vector<int>> dp(sz1, vector<int>(total+1, INT_MAX));
		dp[0][0] = 0;
		
		for (int i = 0; i < sz1; ++i) {
			for (int j = 0; j < total; ++j) {
				if (dp[i][j] == INT_MAX) continue;
				int cur = dp[i][j];
					
				for (int k = 0; k < sz2; ++k) {
					int t = j | (1 << k);
					dp[i][t] = min(dp[i][t], cur + cost[i][k]);
					if (i+1 < sz1 && j != 0) {
						dp[i+1][t] = min(dp[i+1][t], cur + cost[i+1][k]);
					}
				}
			}
		}
		return dp[sz1-1][total-1];
	}
};