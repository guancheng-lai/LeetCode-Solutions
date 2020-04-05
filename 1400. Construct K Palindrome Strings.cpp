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
	bool canConstruct(string s, int k) {
		if (k > s.size()) return false;
		if (k == s.size()) return true;
		
		unordered_map<char, int> m;
		for (auto c : s) {
			m[c]++;
		}
		
		if (std::all_of(m.begin(), m.end(), [](auto p) {return p.second == 1;}) ) {
			return m.size() == k;
		}
		
		for (auto &p : m) {
			p.second %= 2;
		}
		
		
		int count(0);
		for (auto &p : m) {
			if (p.second == 1) {
				count++;
			}
		}
		
		return count <= k;
	}
};

int main(int argc, char *argv[]) {
	
}