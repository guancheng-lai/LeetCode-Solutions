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
	int numJewelsInStones(string J, string S) {
		vector<int> jewel(128,0);
		for (char j : J) {
			jewel[j] = 1;
		}
		
		int res(0);
		for (char s : S) {
			if (jewel[s] != 0) res++;
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.numJewelsInStones("aA", "aAAbbbb");
}