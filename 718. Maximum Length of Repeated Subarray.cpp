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
	int findLength(vector<int>& A, vector<int>& B) {
		if (A.size() == 0 || B.size() == 0) return 0;
		size_t asize = A.size();
		size_t bsize = B.size();
		
		vector< vector<int> > dp(asize+ 1, vector<int>(bsize + 1, 0));
		for (int i = 0; i <= asize; ++i) {
			dp[i][0] = 0;
		}
		
		for (int j = 0; j <= bsize; ++j) {
			dp[0][j] = 0;
		}
		
		int max = 0;
		for (int i = 1; i <= asize; ++i) {
			for (int j = 1; j <= bsize; ++j) {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					max = (max > dp[i][j]) ? max: dp[i][j] ;
				}
			}            
		}
		
		return max;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{ 1,2,3,2,1 };
	vector<int> B{ 3,2,1,4,7 };
	cout << s.findLength(A, B) << " should equal to 3\n";
}