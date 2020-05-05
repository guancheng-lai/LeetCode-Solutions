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
	int findComplement(int num) {
		if (num == 0) return 1;
		if (num == 1) return 0;
		
		vector<int> bs;
		while (num != 0) {
			bs.insert( bs.begin(),num%2 );
			num /= 2;
		}
		
		for (auto &b : bs) {
			b = ( b == 1 ? 0 : 1 );
		}

		int res(0), power(0);
		for (int i = bs.size()-1; i != 0; i--,power++) {
			if (bs[i] == 1) res += pow(2,power);    
		}
		
		return res;

	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.findComplement(5);	
}