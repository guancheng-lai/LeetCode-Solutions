class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		if (m == 0) return 0;
		int n = dungeon[0].size();
		if (n == 0) return 0;
	
		vector< vector<int> > minNeed(m + 1, vector<int>(n + 1, std::numeric_limits<int>::max()));
		minNeed[m][n-1] = 1;
		minNeed[m-1][n] = 1;
		for (int i = m-1; i >= 0; --i) {
			for (int j = n-1; j >= 0; --j) {
				int currNeed = min( minNeed[i+1][j], minNeed[i][j+1] ) - dungeon[i][j];
				if (currNeed <= 0) {
					minNeed[i][j] = 1;
				}
				else {
					minNeed[i][j] = currNeed;
				}
			}
		}
		
		return minNeed[0][0];
	}
};