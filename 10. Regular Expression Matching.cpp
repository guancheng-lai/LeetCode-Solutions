#include <iostream>
#include <string>
#include <string_view>
#include <math.h>
#include <algorithm>
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
	struct hash_pair { 
		template <class T1, class T2> 
		size_t operator()(const pair<T1, T2>& p) const
		{ 
			auto hash1 = hash<T1>{}(p.first); 
			auto hash2 = hash<T2>{}(p.second); 
			return hash1 ^ hash2; 
		} 
	}; 

	unordered_map< pair<string_view,string_view>, int, hash_pair > memo;
	
	bool helper(string_view s, string_view p) {
		if (p.empty()) return s.empty();
		if (memo.count( {s,p} )) return memo[{s,p}];
		
		bool result;
		
		// 2 cases here
		// with * at second position
		if (p.size() >= 2 && p.at(1) == '*') {
			if (helper(s,p.substr(2))) {
				// not checking *
				// * == 0
				result = true;
			}
			else if (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.')) {
				// * == 1 and position [0] match
				result = helper(s.substr(1), p);
			}
			else {
				// position [0] not match
				result = false;
			}
		}
		// without *
		else {
			if (!s.empty() && (p.at(0) == '.' || (p.at(0) == s.at(0)))){
				// match at postion [0]
				// then check positon [1] recursively
				result = helper(s.substr(1), p.substr(1));   
			}
			else {
				// not match at postion [0]
				result = false;
			}
		}
		
		memo[ {s,p} ] = result;
		return result;
	}
	
public:
	bool isMatch(string s, string p) {
		string_view sv(s), pv(p);
		return helper(sv, pv);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	assert(s.isMatch("mississippi", "mis*is*p*.") == false);
}