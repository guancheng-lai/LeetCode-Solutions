#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
using namespace std;

vector<int> kmpProcess(const string &s, size_t sz) {
	vector<int> result(sz, 0);
	int len = 0;
	for (int i = 1; i < s.size();) {
		if (s[i] == s[len]) {
			len++;
			result[i] = len;
			i++;
		}
		else if (len > 0) {
			len = result[len - 1];
		}
		else {
			i++;
		}
	}
	
	return result;
}


int main(int argc, char *argv[]) {
	string s("aabcdadabdddabcd");
	vector<int> v = kmpProcess(s, s.size());
	for (int i = 0; i < s.size(); i++) {
		cout << i << " ";
	}
	cout << endl;
	for (auto c : s) {
		cout << c << " ";
	}
	cout << endl;
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}