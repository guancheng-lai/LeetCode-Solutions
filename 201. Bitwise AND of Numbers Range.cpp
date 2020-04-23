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
	int rangeBitwiseAnd(int m, int n) {
		int i = 0;
		for ( ; m != n; i++) {
			m >>= 1;
			n >>= 1;
		}
		
		return m << i;
	}
};

int main(int argc, char *argv[]) {
	Solution s;	
	assert(4 == s.rangeBitwiseAnd(5, 7));
}