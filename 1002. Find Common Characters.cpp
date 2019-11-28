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
void prtVec(const vector<int> &v) {
	for (auto &i : v) {
		cout << i  << " ";
	}
	cout << endl;
}

vector<string> commonChars(vector<string>& A) {
	vector<int> cnt(26, INT_MAX);
	vector<string> res;
	for (auto s : A) {
		vector<int> cnt1(26, 0);
		for (auto c : s) {
			++cnt1[c - 'a'];
		}
		
		for (auto i = 0; i < 26; ++i) { 
			cnt[i] = min(cnt[i], cnt1[i]);
		}
		
		cout << "cnt  = "; prtVec(cnt);
		cout << "cnt1 = "; prtVec(cnt1);
	}
	
	for (int i = 0; i < 26; ++i) {
		while (cnt[i] > 0) {
			res.push_back( string(1, i + 'a'));
			cnt[i]--;
		}
	}
	
	return res;
}


int main() 
{ 
	vector<string> A {"bella","label","roller"};
	vector<string> r = commonChars(A);
	for (auto s : r) {
		cout << s << " ";
	}
}