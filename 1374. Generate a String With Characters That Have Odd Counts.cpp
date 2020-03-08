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
	string generateTheString(int n) {
		if (n % 2 == 0) {
			string s(n-1, 'a');
			return s + 'b';
		}
		else {
		   return string(n, 'a');
		}
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.generateTheString(3) << endl;
	cout << s.generateTheString(4) << endl;
}