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
public:
	int scoreOfParentheses(string S) {
		stack<int> stk;
		stk.push(0);
		
		for (auto c : S) {
			if (c == '(') {
				stk.push(0);
			}
			else {
				int score = stk.top();
				stk.pop();
				stk.top() += std::max( 2*score, 1);
			}
		}
		
		return stk.top();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.scoreOfParentheses("(()(()))");
}