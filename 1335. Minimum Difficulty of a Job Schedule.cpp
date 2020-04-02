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
public:
    int minDifficulty(vector<int> A, int D) {
		size_t n = A.size();
		if (n < D) return -1;
        
        vector< vector<int> > maxElement(n+1, vector<int>(n+1,0));
		for (int a = 0; a < n; ++a) {
			int currMax(A[a]);
			for (int b = a; b < n; ++b) {
				if (A[b] > currMax) currMax = A[b];
						
				maxElement[a+1][b+1] = currMax;
			}
		}

		A.insert(A.begin(), -99);
		vector< vector<int> > dp(D+1, vector<int>(n+1,1e6));
        
		for (int d = 1; d <= D; ++d) dp[d][0] = A[1];
		for (int i = 1; i <= n; ++i) dp[1][i] = max(dp[1][i-1], A[i]);
		
		for (int d = 2; d <= D; ++d) // Day 2 -> Day D
			for (int i = d; i <= n; ++i) // idx d -> idx n  	Can`t split job if i<d, not enough jobs
				for (int job = d; job <= i; ++job)  // job j=d -> job i
                    dp[d][i] = min( dp[d][i],dp[d-1][job-1]+maxElement[job][i] );
					// calculate each split from d -> i
					
		return dp[D][n];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	int res = s.minDifficulty({1,1,7,1,7,1}, 3);	
//	int res = s.minDifficulty({6,5,4,3,2,1}, 2);	
//	int res = s.minDifficulty({ 11,111,22,222,33,333,44,444 }, 6);	
	int res = s.minDifficulty({ 7,1,7,1,7,1 }, 3);	
//	int res = s.minDifficulty({ 1,1,1 }, 3);	
//	int res = s.minDifficulty({ 9,9,9 }, 4);	
	
	cout << endl << res ;
}