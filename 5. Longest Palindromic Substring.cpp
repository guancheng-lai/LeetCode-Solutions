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
private:
	pair<int, int> helper(const string &s, int l, int r) {
		while (0 <= l && r <= s.size() - 1 && s.at(l) == s.at(r)) {
			l--;
			r++;
		}
		
		l++; r--;
		
		return {l, r};
	}
	
public:    
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}
		
		int longest = 0, start = 0, end = 0;
		for (int i = 0; i < s.size(); ++i) {
			auto [l, r] = helper(s, i, i);
			if (r - l + 1 > longest) {
				start = l;
				end = r;
				longest = r - l + 1;
			}
			
			auto [l2, r2] = helper(s, i, i + 1);
			if (r2 - l2 + 1 > longest) {
				start = l2;
				end = r2;
				longest = r2 - l2 + 1;
			}
		}
		
		return s.substr(start, longest);
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	cout << solution.longestPalindrome("babad");
}