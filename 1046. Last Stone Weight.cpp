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
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq;
		for (auto i : stones) pq.push(i);
		
		while (pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			
			if (a != b) {
				pq.push( a-b );
			}
		}
		
		return (pq.size() == 0) ? 0 : pq.top();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> stones{2,7,4,1,8,1};
	cout << s.lastStoneWeight(stones);	
}