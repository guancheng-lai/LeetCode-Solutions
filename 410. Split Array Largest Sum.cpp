#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string_view>
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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

using ll = long long;

template <typename T>
void printMatrix(const vector< vector<T> > &mat) {
	cout << "\n------MATRIX------\n";
	for (auto &v : mat) {
		for (auto i : v) {
			if (i == std::numeric_limits<ll>::max()) {
				cout << setw(3) << "-" << " ";
			}
			else {
				cout << setw(3) << i << " ";
			}
		}
		cout << endl;
	}
	cout << "------------------\n";
}

class Solution {
public:
	int splitArray(vector<int>& nums, int M) {
		size_t N = nums.size();
		if (M == 1) return accumulate(nums.begin(), nums.end(), 0);
		
		nums.insert(nums.begin(), 0);
		
		vector< vector<ll> > dp_sum(N+1, vector<ll>(N+1,0));
		for (int i = 1; i <= N; ++i) {
			for (int j = i; j <= N; ++j) {
				dp_sum[i][j] = dp_sum[i][j-1] + nums[j];
			}
		}
		
		printMatrix(dp_sum);
		
		
		vector< vector<ll> > dp(M+1, vector<ll>(N+1,std::numeric_limits<ll>::max()));
		
		dp[1][1] = nums[1];
		for (int i = 2; i <= N; ++i) {
			dp[1][i] = dp[1][i-1] + nums[i];
		}
		
		printMatrix(dp);
		
		for (int m = 2; m <= M; ++m)
			for (int i = m; i <= N; ++i)
				for (int j = m; j <= i; ++j)
				{
					dp[m][i] = min( dp[m][i], max( {dp[m-1][j-1],dp_sum[j][i]} ) );
					
					cout << "i=" << i << ",j=" << j << endl;
					printMatrix(dp);
				}
			

		printMatrix(dp);
		
		return dp[M][N];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{ 7,2,5,10,8 };
	cout << s.splitArray(arr, 2);	
}