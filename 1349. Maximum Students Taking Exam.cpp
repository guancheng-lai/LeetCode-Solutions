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
private:
	// void print(const vector<vector<int>> &dp) {
	// 	cout << endl;
	// 	for (auto &v : dp) {
	// 		for (auto i : v) {
	// 			if (i == -1) cout << "   ";
	// 			else cout << i << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// }

public:
	int maxStudents(vector<vector<char>>& seats) {
		int m = seats.size();
		int n = seats[0].size();
		vector<int> seatingChart;
		for (int i = 0; i < m; ++i) {
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				cur = cur * 2 + (seats[i][j] == '.');
			}
			seatingChart.push_back(cur);
		}

		vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
		dp[0][0] = 0;
		for (int i = 1; i <= m; ++i) {
			// cout << "i=" << i << " ";
			int seatingRow = seatingChart[i - 1];
			for (int curr = 0; curr < (1 << n); ++curr) {
				if ((curr & seatingRow) == curr && !(curr & (curr >> 1))) {
					// cout << "curr=" << curr << " ";
					for (int prev = 0; prev < (1 << n); ++prev) {
						if (!(curr & (prev >> 1)) && !((curr >> 1) & prev) && dp[i - 1][prev] != -1) {
							// cout << "prev=" << prev << " ";
							dp[i][curr] = max(dp[i][curr], dp[i - 1][prev] + __builtin_popcount(curr));
							// print(dp);
						}
					}
//					cout << endl;
				}
//				cout << endl;
			}
//			cout << endl;
		}

		return *max_element(dp[m].begin(), dp[m].end());
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<vector<char>> seats{
			{'#','.','#','#','.','#'},
			{'.','#','#','#','#','.'},
			{'#','.','#','#','.','#'}
		};

	cout << s.maxStudents(seats);
}