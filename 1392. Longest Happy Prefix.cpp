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
	string longestPrefix(string s) {
		if (s.size() <= 1) return "";
		string_view result("");
		string_view sv(s);
		for (int i = 1; i < s.size(); ++i) {
			if (sv.substr( 0,i )  == sv.substr( s.size()-i,i )) result = sv.substr(0,i);
		}
		
		return string(result);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.longestPrefix("aaaaa");
}