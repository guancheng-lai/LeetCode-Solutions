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
	vector<string> stringMatching(vector<string>& words) {
		unordered_set<string> s;
		
		for (int i = 0; i < words.size(); ++i) {
			for (int j = 0; j < words.size(); ++j) {
				if (i == j) continue;
				if (words[i].size() > words[j].size()) continue;
				if (words[j].find(words[i]) != string::npos) {
                    s.insert( words[i] );    
                }
			}
		}
		
		vector<string> res{s.begin(), s.end()};
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<string> words{ "mass","as","hero","superhero" };
//	vector<string> words{ "leetcode","et","code" };
//	vector<string> words{ "blue","green","bu" };
//	vector<string> words{ "leetcoder","leetcode","od","hamlet","am" };
//	vector<string> words;
	vector<string> res = s.stringMatching(words);
	for (auto s : res) {
		cout << s << endl;
	}	
}