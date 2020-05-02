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
	int maxDiff(int num) {
		string n = to_string(num);
		string n2(n);
		char exA = ' ';
		for (char &c : n) {
			if (c == '9') continue;
			
			if (exA == ' ') {
				exA = c;
				c = '9';    
			}
			else if (c == exA) {
				c = '9';
			}
		}
		
		// cout << n << endl;
		
		char exclude;
		char exB = ' ';
		char to;
		for (int i = 0; i < n2.size(); ++i) {
			if (n2[i] == '1' && i == 0) {
				exclude = '1';
				continue;
			}
			if (n2[i] == '0') continue;
			
			if (exB == ' ' && n2[i] != exclude) {
				exB = n2[i];
				
				if (i == 0) {
					to = '1';
				}
				else {
					to = '0';
				}
					
				n2[i] = to;
			}
			else if (n2[i] == exB) {
				n2[i] = to;
			}
		}
			
		// cout << n2 << endl;
		
		int res1 = stoi(n);
		int res2 = stoi(n2);
		
		return res1 - res2;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.maxDiff(555);
}