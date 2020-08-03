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
	string decodeString(string s) {
		string res = "";
		stack<int> stk;
		int i = 0;
		stack<string> stkBuffer;
		while (i != s.size()) {
			if (s[i] == ']') {
				int times = stk.top(); stk.pop();
				string s = "";
				while (times--) {
					s += stkBuffer.top();
				}
				stkBuffer.pop();
				if (stkBuffer.empty()) {
					res += s;    
				} else {
					stkBuffer.top() += s;
				}
			} else if (isdigit(s[i])) {
				int start = i;
				int len = 0;
				while (isdigit(s[i++])) {
					len++;
				}
				i--;
				stk.push(stoi(s.substr(start, len)));
				stkBuffer.push("");
			} else {
				if (stk.empty()) {
					res += s[i];
				} else {
					stkBuffer.top() += s[i];
				}   
			}
			
			i++;
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	s.decodeString("3[a]2[bc]");
}	