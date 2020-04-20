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
	int minSwap(vector<int>& A, vector<int>& B) {
		size_t N = A.size();
		vector<int> prevSwap(N); prevSwap[0] = 1;
		vector<int> prevNotSwap(N); prevNotSwap[0] = 0;
		
		auto bothSelfWayIncrease = [&](int i) { return A[i-1] < A[i] && B[i-1] < B[i]; };
		auto interchangeIncrease = [&](int i) { return A[i-1] < B[i] && B[i-1] < A[i]; };
		auto allWayIncrease = [&](int i) { return bothSelfWayIncrease(i) && interchangeIncrease(i); };
		
		for (int i = 1; i < N; ++i) {
			if ( allWayIncrease(i) ) {
				prevNotSwap[i] = min(prevNotSwap[i-1],prevSwap[i-1]);
				prevSwap[i] = min(prevNotSwap[i-1],prevSwap[i-1]) + 1;
			}
			else if( bothSelfWayIncrease(i) ) {
				prevNotSwap[i] = prevNotSwap[i-1];
				prevSwap[i] = prevSwap[i-1] + 1;
			}
			else if ( interchangeIncrease(i) ) {
				prevNotSwap[i] = prevSwap[i-1];
				prevSwap[i] = prevNotSwap[i-1] + 1;
			}
		}
		
		return min(prevSwap.back(), prevNotSwap.back());
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{1,3,5,4,6};
	vector<int> B{1,2,3,7,9};
	cout << s.minSwap(A, B);
}