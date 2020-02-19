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
#include <fstream>
#include <memory>
using namespace std;

class Solution {
public:
	// void printMat(const vector<vector<int>>& matrix) {
	//     for (auto &v : matrix) {
	//         for(auto i:  v) {
	//             cout << i << " ";
	//         }
	//         cout << endl;
	//     }
	//     cout << "------" << endl;
	// }
	
	int maximalSquare(vector<vector<char>>& matrix) {
		size_t m = matrix.size();
		if (m == 0) return 0;
		size_t n = matrix[0].size();
		if (n == 0) return 0;
		
		int result(0);
		vector< vector<int> > dp(m, vector<int>(n, 0));
		for (int r = 0; r < m; ++r) dp[r][0] = (matrix[r][0] == '1') ? 1 : 0, result = max(result, dp[r][0]);
		for (int c = 0; c < n; ++c) dp[0][c] = (matrix[0][c] == '1') ? 1 : 0, result = max(result, dp[0][c]);
		
		for (int r = 1; r < m; ++r) {
			for (int c = 1; c < n; ++c) {
				if (matrix[r][c] == '1') {
					if (dp[r-1][c] == dp[r][c-1]) dp[r][c] = min(dp[r-1][c-1],dp[r][c-1]) + 1;
					else dp[r][c] = min (dp[r-1][c], dp[r][c-1]) + 1;
					
					result = result > dp[r][c] ? result : dp[r][c];
				}
				else {
					dp[r][c] = 0;
				}
				
				// printMat(dp);
			}
		}
		
		return result * result;      
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<char> > mat{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};
	assert(s.maximalSquare(mat) == 4);	
}