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
public:
	vector<int> countBits(int num) {       
		if (num == 0) {
			return vector<int>{0};
		}
		
/* DP */
		vector<int> result(num + 1, 0);
		result[0] = 0;
		result[1] = 1;
	    
		for (int i = 2; i <= num; i *= 2) {
		    for (int j = i; j < 2 * i && j <= num; ++j) {
			    result[j] = 1 + result[j - i];
		    }
		}

/* Built-in function*/
		// vector<int> result(num + 1);
		// result[0] = 0;
		// for (int i = 1; i <= num; ++i) {
		//     bitset<32> bs(i);
		//     result[i] = bs.count();
		// }
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> result = s.countBits(10);
	for (auto &i : result) {
		cout << i << " ";
	}
}