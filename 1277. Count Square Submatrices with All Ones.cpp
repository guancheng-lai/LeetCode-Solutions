class Solution {
// private:
//     template <typename T>
//     void printMatrix(const vector< vector<T> > &mat) {
//         cout << "\nMATRIX:\n";
//         for (auto &v : mat) {
//             for (auto i : v) {
//                 cout << i << " ";
//             }
//             cout << endl;
//         }
//         cout << "\n-------------\n";
//     }
	
public:
	int countSquares(vector<vector<int>>& matrix) {
		size_t m = matrix.size(), n = matrix[0].size();
		
		int result(0);
		vector< vector<int> > dp(m, vector<int>(n, 0));
		for (int r = 0; r < m; ++r) if (matrix[r][0] == 1) { dp[r][0] = 1, result++; }
		for (int c = 1; c < n; ++c) if (matrix[0][c] == 1) { dp[0][c] = 1, result++; }
		
		for (int r = 1; r < m; ++r) {
			for (int c = 1; c < n; ++c) {
				if (matrix[r][c] == 0) continue;

				if (dp[r-1][c] == dp[r][c-1]) dp[r][c] = min(dp[r-1][c-1],dp[r][c-1]) + 1;
				else dp[r][c] = min (dp[r-1][c], dp[r][c-1]) + 1;
				
				result += dp[r][c];
				// printMatrix(dp);
			}
		}
		
		return result;
	}
};