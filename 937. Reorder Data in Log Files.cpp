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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		if (logs.size() <= 1) return logs;
		
		vector<string> digitLogs;
		
		// Spliting the digit-logs and letter-logs
		for (vector<string>::iterator vsit = logs.begin(); vsit != logs.end(); vsit++) {
			int idx = (*vsit).find(' ') + 1;
				
			// Move digit-logs to another vector
			if (isdigit( (*vsit).at(idx) )) {
				std::move(vsit, vsit+1, std::back_inserter(digitLogs));
				logs.erase(vsit);
				vsit--;
			}
		}

		// sort the letter-logs
		stable_sort(logs.begin(), logs.end(),[](const string &s1, const string &s2) {
			int idx1 = s1.find(' ') + 1;
			int idx2 = s2.find(' ') + 1;
			
			if ( s1.substr(idx1) == s2.substr(idx2) ) {
			   return lexicographical_compare(s1.begin(), s1.begin()+idx1, s2.begin(), s2.begin()+idx2);
			}
			else {                    
				return lexicographical_compare(s1.begin()+idx1, s1.end(), s2.begin()+idx2, s2.end());
			}
		});
		
		// put the digit-logs to the back of the letter-logs
		logs.insert(logs.end(), digitLogs.begin(), digitLogs.end());
		return logs;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	
	cout << "Test case #1" << endl;
	vector<string> logs{ "1 n u", "r 527", "j 893", "6 14", "6 82" };
	vector<string> result = s.reorderLogFiles(logs);
	for (auto &s : result) cout << s << endl;
	cout << endl;
	
	cout << "Test case #2" << endl;
	vector<string> logs2{ "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };
	vector<string> result2 = s.reorderLogFiles(logs2);
	for (auto &s : result2) cout << s << endl;
	cout << endl;
}