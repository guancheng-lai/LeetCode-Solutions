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
	unordered_map<string_view, string> m;
	
	string entityParser(string text) {
		m["&quot;"] = "\"";
		m["&apos;"] = "\'";
		m["&amp;"] = '&';
		m["&gt;"] = ">";
		m["&lt;"] = '<';
		m["&frasl;"] = "/";
		
		string_view sv(text);
		int len = sv.size();
		string res("");
		for (int i = 0; i < len; ++i) {
			if (i + 3 < len) {
				auto it = m.find( sv.substr(i,4) );
				if (it != m.end()) {
					res += m[sv.substr(i,4)];
					i += 3;
					continue;	
				}
			}
			
			if (i + 4 < len) {
				auto it = m.find( sv.substr(i,5) );
				if (it != m.end()) {
					res += m[sv.substr(i,5)];
					i += 4;
					continue;
				}
			}
			
			if (i + 5 < len) {
				auto it = m.find( sv.substr(i,6) );
				if (it != m.end()) {				
					res += m[sv.substr(i,6)];
					i += 5;
					continue;
				}
			}
			
			if (i + 6 < len) {
				auto it = m.find( sv.substr(i,7) );
				if (it != m.end()) {
					res += m[sv.substr(i,7)];
					i += 6;
					continue;
				}
			}
			
			res += sv.at(i);
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	string text = "&amp; is an HTML entity but &ambassador; is not.";
	string res = s.entityParser(text);
	cout << res;
}