class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int m = A.size();
		int n = A[0].size();
		for (int r = 1; r < m; ++r) {
			for (int c = 0; c < n; ++c) {
				int left = std::numeric_limits<int>::max();
				if (c > 0) left = A[r-1][c-1];
				
				int mid = A[r-1][c];
				
				int right = std::numeric_limits<int>::max();
				if (c < n-1) right = A[r-1][c+1];
				
				A[r][c] += min( {left, mid, right} );
			}
		}

		return *( min_element(A.back().begin(), A.back().end()) );
	}
};