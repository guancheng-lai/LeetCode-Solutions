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
	bool checkIfCanBreak(string s1, string s2) {
		vector<char> v1,v2;
	
		for (int i = 0; i < s1.size(); ++i) {
			v1.push_back(s1[i]);
			v2.push_back(s2[i]);
		}

		sort(v1.begin(),v1.end());
	    sort(v2.begin(),v2.end());

		bool b2 = true;
		for (int i = v1.size()-1; i >= 0; --i) {
			// cout << v1[i] << " " << v2[i] << endl;
			if (v1[i] > v2[i]) {
				b2 = false;
			}
		}

		// cout << endl;

		bool b1 = true;
		for (int i = v1.size()-1; i >= 0; --i) {
			// cout << v1[i] << " " << v2[i] << endl;
			if (v1[i] < v2[i]) {
				b1 = false;
			}
		}

		return b1 || b2;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	assert(s.checkIfCanBreak("leetcodee", "interview") == true);
}