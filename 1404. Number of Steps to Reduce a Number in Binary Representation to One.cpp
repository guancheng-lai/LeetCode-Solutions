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
	int numSteps(string s) {
		bitset<70> bs(s);
		cout << bs << endl;
		int count(0);
		while (!(bs.test(0) == 1 && bs.count() == 1)) {
			if (bs.test(0) == 1) {
				int idx(0);
				while (bs.test(idx) == 1) {
					bs.reset(idx++);
				}
				bs.set(idx);
			}
			else {
				bs>>=1;
			}
			
			count++;
			cout <<  bs << endl;
		}
		
		return count;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.numSteps("1111011110000011100000110001011011110010111001010111110001");
}
