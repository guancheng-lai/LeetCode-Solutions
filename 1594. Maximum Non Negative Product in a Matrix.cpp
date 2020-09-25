class Solution {
public:
	using ll = long long;
	int MOD = 1e9 + 7;
	int maxProductPath(vector<vector<int>>& grid) {
		int ROW = grid.size(), COL = grid[0].size();
		vector< vector< pair<ll,ll> >> path(ROW, vector< pair<ll,ll> >(COL, {0,0}));
		path[0][0] = {grid[0][0], grid[0][0]};
		for (int r = 1; r < ROW; ++r) {
			ll num = path[r-1][0].first * grid[r][0];
			path[r][0] = {num, num};
		}
		
		for (int c = 1; c < COL; ++c) {
			ll num = path[0][c-1].first * grid[0][c];
			path[0][c] = {num, num};
		}
		
		for (int r = 1; r < ROW; ++r) {
			for (int c = 1; c < COL; ++c) {
				ll maxPos, minNeg;
				if (grid[r][c] < 0) {
					maxPos = min(path[r][c-1].second, path[r-1][c].second) * grid[r][c];
					minNeg = max(path[r][c-1].first, path[r-1][c].first) * grid[r][c];
				} else {
					maxPos = max(path[r][c-1].first, path[r-1][c].first) * grid[r][c];
					minNeg = min(path[r][c-1].second, path[r-1][c].second) * grid[r][c];
				}
				path[r][c] = {maxPos, minNeg};
			}
		}
		
		ll maxNonNeg = path.back().back().first % MOD;
		return maxNonNeg < 0 ? -1 : maxNonNeg;
	}
};