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
	int maxProfit(vector<int>& prices) {
		int buy1, buy2, sell1, sell2;
		buy1 = buy2 = std::numeric_limits<int>::max();
		sell1 = sell2 = 0;
		for (const auto i : prices) {
			buy1 = std::min( buy1,i );
			sell1 = std::max( sell1,i-buy1 );
			
			buy2 = std::min( buy2,i-sell1 );
			sell2 = std::max( sell2,i-buy2 );
			
			// cout << buy1 << " " << sell1 << " " << buy2 << " " << sell2 << endl;
		}
		
		return sell2;
	}
};

int main(int argc, char *argv[]) {
	vector<int> arr{ 3,3,5,0,0,3,1,4 };
	Solution s;
	cout << s.maxProfit(arr);
}