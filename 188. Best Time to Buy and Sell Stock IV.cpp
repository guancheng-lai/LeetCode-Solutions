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
	int maxProfit(int k, vector<int> prices) {
		if (k <= 0 || prices.size() <= 1) return 0;
		
		k = std::min( k,int(prices.size()/2) );
		vector<int> buy( k,std::numeric_limits<int>::max() );
		vector<int> sell( k,0 );
		
		for (const int p : prices) {
			if (p < buy[0]) buy[0] = p;
			if (p-buy[0] > sell[0]) sell[0] = p-buy[0];
			
			// buy[0] = std::min( buy[0],p );
			// sell[0] = std::max( sell[0],p-buy[0] );
			
			for (int i = 1; i < k; ++i) {
				if (p-sell[i-1] < buy[i]) buy[i] = p-sell[i-1];
				if (p-buy[i] > sell[i]) sell[i] = p-buy[i];
				
//                 buy[i] = std::min( buy[i],p-sell[i-1] );
//                 sell[i] = std::max( sell[i],p-buy[i] );
			}
		}
		
		return sell.back();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.maxProfit( 2,{ 3,2,6,5,0,3 } );
}