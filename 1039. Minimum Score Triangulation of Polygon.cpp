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
    int memo[51][51] = {0};
    
	int dfs(vector<int> &A, int start, int end) {
		if ( start >= end-1 ) return 0;
		if (memo[start][end] != 0 ) return memo[start][end];
		
		int res = std::numeric_limits<int>::max();
		for (int i = start+1; i < end; ++i) {
			int sum = A[start]*A[i]*A[end] + dfs( A,start,i ) + dfs( A,i,end );
            if (sum < res) res = sum;
		}
		
		memo[start][end] = res;
		return res;
	}
	
public:
	int minScoreTriangulation(vector<int>& A) {
		return dfs(A,0,A.size()-1);
	}
};

int main(int argc, char *argv[]) {
	
}