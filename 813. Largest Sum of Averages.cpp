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

template <typename T>
void printMatrix(const vector< vector<T> > &mat) {
	cout << "\n------------------------MATRIX------------------------\n";
	for (auto &v : mat) {
		for (auto i : v) {
			cout << std::setw(7) << i << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------------\n";
}

class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		size_t N = A.size();
		vector< vector<double> > dp_avg(N+1, vector<double>(N+1));
		for (int i = 0; i < N; ++i) {
			double sum(0), cnt(0);
			for (int j = i; j < N; ++j) {
				sum += A[j]; 
				cnt++;
				dp_avg[i+1][j+1] = sum/cnt;
			}
		}
		
		printMatrix(dp_avg);
		
		A.insert(A.begin(), -1);
		vector< vector<double> > dp(K+1, vector<double>(N+1,0));
		
		for (int i = 1; i <= N; ++i) dp[1][i] = dp_avg[1][i];
		printMatrix(dp);
		
		for (int k = 2; k <= K; ++k) {
			for (int i = 1; i <= N; ++i) {
				for (int a = k; a <= i; ++a) {
					dp[k][i] = std::max( dp[k][i],dp[k-1][a-1]+dp_avg[a][i] );
				}
			}
		}
		
//		printMatrix(dp);
		
		return dp[K][N];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{9,1,2,3,9};
	int res = s.largestSumOfAverages(A, 3);	
	cout << endl << res ;
}