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
bool checkInclusion(string s1, string s2) {
		vector<int> origin(26, 0);
		for (auto c : s1) origin[c-'a']++;
		vector<int> inprogress(26, 0);
		
		int curr = 0;
		for (int i = 0, end = s2.size(); i < end; ++i) {
			for (int j = i, end2 = i + s1.size(); j < end2 && j < end; ++j) {
				int curr = s2.at(j) - 'a';
				if (origin[curr] <= 0 || inprogress[curr] >= origin[curr]) {
					break;
				}

				inprogress[curr]++;
			}
			
			if (inprogress == origin) return true;
			
			for (int i = 0; i < 26; ++i) inprogress[i] = 0;
		}
		
		return false;
	}

};

int main(int argc, char *argv[]) {
	Solution s;
	assert(s.checkInclusion("adc", "cdca"));	
}