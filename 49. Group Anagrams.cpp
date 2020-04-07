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
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.empty()) return vector<vector<string>>();
		if (strs.size() == 1) return vector< vector<string> > (1, strs);
		
		unordered_map< string, vector<string> > m;

		for (auto && str : strs) {
			string s = str;
			sort(s.begin(), s.end());
			if (m.count(s)) {
				m[s].push_back(str);
			}
			else {
				vector<string> vs{str};
				m[s] = vs;
			}
		}
		
		vector< vector<string> > result;
		for (auto &&[k,v] : m) {
			result.push_back(v);
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< string > vs {"eat","tea","tan","ate","nat","bat"};
	auto res = s.groupAnagrams(vs);
	for (auto &v : res) {
		cout << "[";
		for (auto &s : v) {
			cout << " " << s << " ";
		}
		cout << "]";
	}
}