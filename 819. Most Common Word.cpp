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
	// template <typename T1, typename T2>
	// void printMap(const map<T1, T2> &m) {
	//     cout << "\nMAP: ";
	//     for (auto &it : m) {
	//         cout << it.first << "=" << it.second << " ";
	//     }
	//     cout << "\n------------\n";
	// }

public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		if (paragraph.empty()){
			return string();
		}
		
		set<string> ban;
		for (auto &word : banned) {
			for (auto &c : word) {
				c = tolower(c);
			}
			ban.insert(word);
		}
		
		for (auto &c : paragraph) {
			if (isalpha(c)) {
				c = tolower(c);
			}
		}
		
		map<string, int> mp;
		for (int i = 0, end = paragraph.size(); i < end;) {
			// cout << i << " ";
			while ( i < end && !isalpha(paragraph[i]) ) {
				i++;
			}
			
			int start = i;
			while ( i < end && isalpha(paragraph[i]) ) {
				i++;
			}
			
			int len = i - start;
			if (len > 0) {
				string word = paragraph.substr(start, len);
				if (ban.count(word) == 0) {
				mp[word] ++;
				
				}
			}
		}
		
		// printMap(mp);
		
		int maxOccur = 0;
		string result;
		for (auto &it: mp) {
			if (it.second > maxOccur) {
				result = it.first; 
				maxOccur = it.second;
			}
		}

		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
	vector<string> banned { "hit" };
	cout << solution.mostCommonWord(paragraph, banned);
}