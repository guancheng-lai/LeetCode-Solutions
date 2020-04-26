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
	int maxScore(string s) {
		int zero(0), one(0);
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') zero++;   
			else one++;
		}
		
		int score(one);
		if (s[0] == '0') score++;
		else score--;
		
		int maxScore(score);
		for (int i = 1; i < s.size()-1; ++i) {
			if (s[i] == '0') score++;
			else score--;
			
			maxScore = max(score, maxScore);
		}
		
		return maxScore;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.maxScore("011101");
}