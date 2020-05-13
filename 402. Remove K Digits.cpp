#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>
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
	string removeKdigits(string num, int k) 
	{
		if (num.size() == k) return "0";
		if (k == 0) return num;
		
		stack<int> stk;
		for (auto c : num)
		{
			int i = c - '0';
			while (k > 0 && !stk.empty() && stk.top() > i) 
			{ 
				k--, stk.pop(); 
			}
			
			stk.push(i);
		}
		
		while(k > 0 && !stk.empty()) 
		{ 
			k--, stk.pop(); 
		}
		
		stringstream ss;
		while (!stk.empty()) 
		{
			ss << stk.top();
			stk.pop();
		}
		
		string res = ss.str();
		reverse(res.begin(), res.end());
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
		return res.size() == 0 ? "0" : res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.removeKdigits("1432219", 3);
}