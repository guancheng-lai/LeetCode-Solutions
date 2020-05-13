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
	int shortestSubarray(vector<int>& A, int K) {
		int N = A.size();
		vector<int> preSum(N,0);
		preSum[0] = A[0];
		for (int i = 1; i < N; ++i) preSum[i] = preSum[i-1] + A[i];
		
		deque<int> deq;
		int res = N+1;
	
		for (int i = 0; i < N; ++i)
		{
			if (preSum[i] >= K)
			{
				res = min(res, i+1);
			}
			
			while (!deq.empty() && preSum[i] - preSum[deq.front()] >= K)
			{
				res = min(res, i - deq.front());
				deq.pop_front();
			}
			
			while (!deq.empty() && preSum[i] <= preSum[deq.back()])
			{
				deq.pop_back();
			}
			
			deq.push_back(i);
		}
		
		return res == N+1 ? -1 : res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{ 84,-37,32,40,95 };
	cout << s.shortestSubarray(A, 167);	
}