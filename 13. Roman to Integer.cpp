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
private:
	int getValue(char c) {
		switch(c) {
			case 'I' : return 1;
			case 'V' : return 5;
			case 'X' : return 10;
			case 'L' : return 50;
			case 'C' : return 100;
			case 'D' : return 500;
			case 'M' : return 1000;
		}
		
		return 0;
	}
	
	bool hasSub(const string &s) {
		if (s.at(0) == 'I' && (s.at(1) == 'V' || s.at(1) == 'X') ) {
			return true;
		}
		
		if (s.at(0) == 'X' && (s.at(1) == 'L' || s.at(1) == 'C') ) {
			return true;
		}
		
		if (s.at(0) == 'C' && (s.at(1) == 'D' || s.at(1) == 'M') ) {
			return true;
		}
		
		return false;
	}
	
public:
	int romanToInt(string s) {
		if (s.empty()) { return 0; }
		if (s.size() == 1) { return getValue(s.at(0)); }
		
		if (hasSub(s)) {
			return getValue(s.at(1)) - getValue(s.at(0)) + romanToInt(s.substr(2));
		}
		
		return getValue(s.at(0)) + romanToInt(s.substr(1));
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.romanToInt("MCMXCIV") << " should equal to 1994\n";
}