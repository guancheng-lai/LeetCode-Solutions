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
	int maxProfit(vector<int>& prices) 
	{
		if (prices.size() < 2) return 0;
		
		int maxProfit(0);
		int minSoFar(prices[0]);
		
		for (int i = 1; i < prices.size(); ++i)
		{
			minSoFar = std::min( minSoFar,prices[i] );
			maxProfit = std::max( maxProfit,prices[i]-minSoFar );
			// if (prices[i] < minSoFar)
			// {
			//     minSoFar = prices[i];    
			// }
			// else if (prices[i] - minSoFar > maxProfit)
			// {
			//     maxProfit = prices[i] - minSoFar;
			// }

		}
		
		return maxProfit;
	}
};

int main(int argc, char *argv[]) {
	vector<int> arr{ 7,1,5,3,6,4 };
	Solution s;
	cout << s.maxProfit(arr);
}