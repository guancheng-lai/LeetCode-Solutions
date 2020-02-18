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
	int getSmallest(vector<int> &arrUgly, int &a, int &b, int &c) {
		int a2 = arrUgly[a]*2, b3 = arrUgly[b]*3, c5 = arrUgly[c]*5;
		if (a2 <= b3 && a2 <= c5) {
			a++;
			return a2;
		}
		
		if (b3 <= a2 && b3 <= c5) {
			b++;
			return b3;
		}
		
		c++;
		return c5;
	}

public:
	int nthUglyNumber(int n) {
		if (n <= 0) return 0;
		int idxOf2 = 0, idxOf3 = 0, idxOf5 = 0;
		vector<int> arrUgly{ 1 };
		for (int i = 2; i <= n; ++i) {
			int next = getSmallest(arrUgly, idxOf2, idxOf3, idxOf5);
			while (next <= arrUgly.back()) {
				next = getSmallest(arrUgly, idxOf2, idxOf3, idxOf5);
			}
			
			arrUgly.push_back(next);
		}
		
		return arrUgly.back();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	for (int i = 1; i <= 1690; ++i) cout << i << ": " << s.nthUglyNumber(i) << endl;	
}