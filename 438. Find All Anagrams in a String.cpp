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
	vector<int> findAnagrams(string s, string p) {
		vector<int> a1(26,0);
		for (auto c : p) a1[c-'a']++;
		
		vector<int> a2(26,0);
		for (int i = 0; i < p.size(); ++i) a2[ s[i]-'a' ]++;
		
		vector<int> res;
		for (int i = 0; i <= s.size()-p.size(); ++i)
		{
			if (a1 == a2) res.push_back(i);
			
			int l = i, r = i + p.size();
			a2[ s[l]-'a' ]--;
			a2[ s[r]-'a' ]++;
		}
		
		if (a1 == a2) res.push_back(s.size()-p.size());
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	auto v = s.findAnagrams("abab", "ab");	
	for (auto i : v) cout << i << " ";
}