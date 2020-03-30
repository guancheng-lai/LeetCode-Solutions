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

class Solution {
private:
	template <typename T>
	void printMatrix(const vector< vector<T> > &mat) {
		cout << "------MATRIX------\n";
		for (auto &v : mat) {
			for (auto i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
		cout << "------------------\n";
	}
	
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		size_t sizeA = A.size(), sizeB = B.size();
		vector< vector<int> > dp(sizeA+1, vector<int>(sizeB+1,0));
		for (int a = 1; a <= sizeA; ++a) {
			for (int b = 1; b <= sizeB; ++b) {
				if (A[a-1] == B[b-1]) {
					dp[a][b] = dp[a-1][b-1] + 1;
				}
				else {
					dp[a][b] = max( dp[a][b-1],dp[a-1][b] );
				}
				
				// printMatrix(dp);
			}
		}
		
		return dp[sizeA][sizeB];
	}
};

int main(int argc, char *argv[]) {
	vector<int> A{ 1,4,2 };
	vector<int> B{ 1,2,4 };
	Solution s;
	cout << s.maxUncrossedLines(A, B);
}