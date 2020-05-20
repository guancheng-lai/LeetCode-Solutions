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
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
		map<int, vector<string> > m;
		size_t start = 0;
		size_t it = text.find(' ');
		while (it != std::string::npos) {
			int len = it - start;
			string str = text.substr(start,len);
			m[len].push_back( str );
			start = it+1;
			it += 2;
			it = text.find(' ', it);
		}
		
		m[text.size() - start].push_back( text.substr(start) );
		
		string res = "";
		for (auto &[k,vs] : m) 
		{
			for (auto &s : vs)
			{
				res += (s + ' ');
			}
		}
		
//		res = res.substr(1);
		res[0] = toupper(res[0]);
		res.pop_back();
		
		return res;
	}

};

int main(int argc, char *argv[]) {
	
}