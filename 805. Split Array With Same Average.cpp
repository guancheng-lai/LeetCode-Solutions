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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
public:
	void prt(const vector< vector<int> > &vv) {
		int i = 0;
		for (auto &v : vv) {
			cout << i++ << ": ";
			for (auto item : v) {
				cout << item << " ";
			}
			cout << endl;
		}
		
		cout << "------------" << endl;
	}
	
	
	bool splitArraySameAverage(vector<int>& A) {
		int len = A.size();
		int halfLen = len / 2;
		int sum = accumulate(A.begin(), A.end(), 0.0);
		
		bool exist = false;
		for (int i = 1; i <= halfLen; ++i)
			if ((sum * i) % len == 0)
				exist = true;
		
		if (!exist) return false;
		
		vector< vector<int> > dp(sum+1, vector<int>(halfLen+1, 0));
		dp[0][0] = 1;
		
		
		for (int a : A) {
			for (int i = sum; i >= a; --i) {
				for (int j = 1; j <= halfLen; ++j) {
					dp[i][j] = dp[i][j] || dp[i - a][j - 1];
					
					// prt(dp);
				}
			}
		}
		
		for (int i = 1; i <= halfLen; ++i) {
			if (sum * i % len == 0 && dp[sum * i / len][i]) return true;
		}
		
		return false;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> v{1,2,3,4,5,6,7,8};
	s.splitArraySameAverage(v);	
}