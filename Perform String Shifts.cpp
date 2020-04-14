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
	string stringShift(string s, vector<vector<int>>& shift) {
		int shiftLeft(0);
		for (auto &v : shift) {
			if (v[0] == 0) shiftLeft += v[1];
			else shiftLeft -= v[1];
		}
		
		if ( abs(shiftLeft) % s.size() == 0) return s;
		
		if (shiftLeft > 0) {
			shiftLeft %= s.size();
			string right = s.substr(0,shiftLeft);
			string left = s.substr(shiftLeft);
			return left + right;
		}
		else {
			shiftLeft = -(abs(shiftLeft) % s.size());
			string left = s.substr(s.size() + shiftLeft);
			string right = s.substr( 0,s.size() + shiftLeft );
			return left + right;
		}
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	vector< vector<int> > shift{ {0,1},{1,2} };
//	cout << s.stringShift("abc", shift);	
	
	vector< vector<int> > shift{ {1,4},{0,7},{0,8},{0,7},{0,6},{1,3},{0,1},{1,7},{0,5},{0,6} };
	cout << s.stringShift("xqgwkiqpif", shift);	
}