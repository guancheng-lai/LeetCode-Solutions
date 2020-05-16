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
    int gcd(int a, int b) {
	    return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    vector<string> simplifiedFractions(int n) {
		if (n == 1) return vector<string>();
		
		vector<string> res;
		for (int dt = 2; dt <= n; ++dt) {
			for (int nt = 1; nt < dt; ++nt) {
				if ( gcd(dt,nt) == 1 ) {
					string s = to_string(nt);
					s += "/";
					s += to_string(dt);
					res.emplace_back(s);
				}
			}
		}
		
		return res;
	}

};

int main(int argc, char *argv[]) {
	Solution s;
	vector<string> res = s.simplifiedFractions(4);
	for (auto s : res) cout << s << endl;
}