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
	string reverseParentheses(string s) {
		int N = s.size();
		if (N < 1) return "";
		
		vector< pair<int,int> > q;
		stack<int> stk;
		for (int i = 0; i < N; ++i) 
		{
			if (s[i] == '(') stk.push(i);
			else if (s[i] == ')') 
			{
				int left = stk.top(); stk.pop();
				q.emplace_back( make_pair(left,i) );
			}
		}
		
		for (auto &[l,r] : q)
		{
			std::reverse(s.begin() + l, s.begin() + r);    
		}
		
		string res = "";
		for (auto c : s) 
		{
			if (c == '(' || c == ')') continue;
			
			res += c;
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	
}