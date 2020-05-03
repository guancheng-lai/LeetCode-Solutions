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
	bool canConstruct(string ransomNote, string magazine) {
		map<char,int> rm, mm;
		for (char c : magazine) mm[c]++;
		for (char c : ransomNote) rm[c]++;
		
		for (auto &[k,v] : rm) {
			auto it = mm.find(k);
			if (it->second < v) return false;
		}
		
		return true;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	assert( s.canConstruct("aa", "aab") == true );
}