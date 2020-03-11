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
	int integerBreak(int n) {
		if (n == 2) return 1;
		if (n == 3) return 2;
		
		int prod = 1;
		while (n > 4) {
			n -= 3;
			prod *= 3;
		}
		
		return prod * n;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.integerBreak(10);	
}