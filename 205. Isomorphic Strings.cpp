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
	// template <typename T>
	// void printVector(const vector<T> &v) {
	//     cout << "\n-------------\nVECTOR: ";
	//     for (auto &i : v) {
	//         cout << i << " ";
	//     }
	//     cout << "\n-------------\n";
	// }
		
	void processing(string const &s, vector<int> &chars, vector<int> &info) {
		int larger = 0;
			
		for (int i = 0; i < s.size(); ++i) {
			char c = s.at(i);
			int idx = c;
			if (chars[ idx ] == -1) {
				chars[idx] = i;
				info[i] = larger++;
			}
			else {
				info[i] = info[ chars[idx] ];
			}
		}
	}
public:
	bool isIsomorphic(string s, string t) {
		vector<int> chars_s(256, -1);
		vector<int> info_s(s.size());
		processing(s, chars_s, info_s);
		
		vector<int> chars_t(256, -1);
		vector<int> info_t(s.size());
		processing(t, chars_t, info_t);
			
		// printVector(chars_s);
		// printVector(info_s);
		
		// printVector(chars_t);
		// printVector(info_t);
			
		auto equal = [] (const vector<int> &va, const vector<int> &vb) { 
			for (int i = 0; i < va.size(); ++i) {
				if (va[i] != vb[i]) { 
					return false;
				}
			}
				
			return true;
		};
			
		return equal(info_s, info_t);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	if(s.isIsomorphic("abb", "cdd")) {
		cout << "They are isomorphic\n";
	}
	else {
		cout << "They are not isomorphic\n";
	}
}