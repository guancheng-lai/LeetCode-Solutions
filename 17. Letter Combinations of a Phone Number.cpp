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
	vector<char> getChars(char c) {
		switch(c){
			case '2' : return vector<char>{'a','b','c'};
			case '3' : return vector<char>{'d','e','f'};
			case '4' : return vector<char>{'g','h','i'};
			case '5' : return vector<char>{'j','k','l'};
			case '6' : return vector<char>{'m','n','o'};
			case '7' : return vector<char>{'p','q','r','s'};
			case '8' : return vector<char>{'t','u','v'};
			case '9' : return vector<char>{'w','x','y','z'};
		}
		
		return vector<char>();
	}    
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty() || find(digits.begin(), digits.end(), '1') != digits.end()) {
			return vector<string>();
		}
		
		vector<string> result{""};
		
		for (auto &digit : digits) {
			vector<string> temp;
			vector<char> listChars = getChars(digit);
			if (listChars.empty()) return vector<string>();
			
			for (auto &r : result) {                
				for (auto &c: listChars) {
					temp.push_back(r + c);
				}
			}
			
			result = std::move(temp);
		}
		
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<string> result = s.letterCombinations("234");
	for (auto &s : result) {
		cout << s << endl;
	}
}