class Solution {
public:
	int N;
	vector< vector<int> > memo;
	
	int dfs(vector<int>& piles, int start, int end) {
		if (start > end) return 0;
		if (start == end) return piles[start];
		if (start + 1 == end) return std::max(piles[start], piles[end]);
		if (memo[start][end] != -1) return memo[start][end];
		
		int takeLeft = piles[start] + dfs(piles, start + 2, end);
		int takeRight = piles[end] + dfs(piles, start, end - 2);
		int res = std::max(takeLeft, takeRight);
		return memo[start][end] = res;
	}
	
	bool stoneGame(vector<int>& piles) {
		N = piles.size();
		memo.assign(N, vector<int>(N, -1));
		int sum = std::accumulate(piles.begin(), piles.end(), 0.0);
		int alex = dfs(piles, 0, N-1);
		int lee = sum - alex;
		return alex > lee;
	}
};