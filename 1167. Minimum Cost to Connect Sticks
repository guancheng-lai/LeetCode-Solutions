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
	int connectSticks(vector<int>& sticks) {
		if (sticks.size() <= 1) return 0;
		if (sticks.size() == 2) return sticks[0] + sticks[1];
		
		priority_queue<int, vector<int>, std::greater<int> > pq;
		for (auto &i : sticks) {
			pq.push(i);
		}
		
		int result(0);
		while (pq.size() > 1){
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			result += (a + b);
			pq.push(a + b);
		}
		
		return result;   
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	vector<int> v{1,8,3,5};
	cout << solution.connectSticks(v);
}