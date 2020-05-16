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
	int maxPower(string s) {
		if (s.size() == 0) return 0;
		if (s.size() == 1) return 1;
		unordered_map<char,int> mp;
		int cnt(1);
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == s[i-1]) {
				cnt++;
			}
			else {
				mp[ s[i-1] ] = max(mp[ s[i-1] ], cnt);
				cnt = 1;
			}
		}
		
		mp[ s[s.size()-1] ] = max(mp[ s[s.size()-1] ], cnt);
		
		int res(0);
		for (auto &[k,v] : mp) {
			res = max(res,v);    
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.maxPower("leetcode");
}