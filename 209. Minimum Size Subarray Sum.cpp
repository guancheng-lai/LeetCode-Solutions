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
	int minSubArrayLen(int K, vector<int>& A) {
		deque<int> deq;
		int sum = 0, res = INT_MAX;
		
		for (int i = 0, end = A.size(); i < end; ++i)
		{
			if (sum < K)
			{
				deq.push_front(A[i]);
				sum += A[i];
			}

			while (sum >= K && !deq.empty())
			{
				if (deq.size() < res) res = deq.size();
				sum -= deq.back();
				deq.pop_back();
			}
		}
		
		return res == INT_MAX ? 0 : res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{ 2,3,1,2,4,3 };
	cout << s.minSubArrayLen(7, A);	
}