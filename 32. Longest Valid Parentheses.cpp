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
	int longestValidParentheses(string s) {
		int start = 0, end = s.size()-1;
		while (s[start] == ')') { start++; }
		while (s[end] == '(') { end--; }
	
		int res = 0, i = start, mostFarStart = -1;
		stack<int> stk;
		while (i <= end) {
			if (s[i] == '(') {
				int itemToPush = (mostFarStart == -1) ? i : mostFarStart;
				stk.push(itemToPush);
				
				mostFarStart = -1;
			} else {
				if (stk.empty()) {
					mostFarStart = -1;
					i++; 
					continue;
				}
								
				mostFarStart = stk.top();
				
				int currLen = i - stk.top() + 1; stk.pop();
				if (currLen > res) res = currLen;
			}
			
			i++;
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.longestValidParentheses(")()())()()(");
}