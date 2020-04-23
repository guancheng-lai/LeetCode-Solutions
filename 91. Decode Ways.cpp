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
	int N;
	vector<int> memo;
	
	int dfs(const string &s, int i) {
		if (i == N) return 1;
		if (s[i] == '0') return 0;
		
		if (memo[i] != -1) return memo[i];
		
		int res = dfs(s,i+1);
		if (i >= N-1) {
			memo[i] = res;
			return res;
		}
		
		if (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6') ) res += dfs(s,i+2);
		memo[i] = res;
		return res;
	}
	
public:
	int numDecodings(string s) {
		this->N = s.size();
		this->memo.resize(N,-1);
		return N==0 ? 0 : dfs(s, 0);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.numDecodings("12");	
	assert(s.numDecodings("12") == 2);
}