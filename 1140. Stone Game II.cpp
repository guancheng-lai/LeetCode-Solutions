class Solution {
public:
	vector< vector<int> > dp;
	int N;
	
	int dfs(vector<int>& A, int start, int M, int totalPiles) {
		if (start >= N) return 0;
		if (N - start <= 2 * M) return totalPiles;
		if (dp[start][M] != -1) return dp[start][M];
		int res = 0, taken = 0;
		for (int i = start; i < std::min(N, start + 2 * M); ++i) {
			taken += A[i];
			res = std::max(res, totalPiles - dfs(A, i+1, std::max(M, i-start+1), totalPiles - taken));
		}
		return dp[start][M] = res;
	}
	
	int stoneGameII(vector<int>& A) {
		N = A.size();
		int sum = std::accumulate(A.begin(), A.end(), 0.0);
		dp.assign(N, vector<int>(N, -1));
		return dfs(A, 0, 1, sum);
	}
};

