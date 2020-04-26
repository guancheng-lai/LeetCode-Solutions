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
	int maxScore(vector<int>& A, int k) {
		int sum = accumulate(A.begin(), A.begin() + k, 0.0);
		int res = sum;
		int i = k-1, end = A.size()-1;
		while (i >= 0) {
			sum -= A[i];
			sum += A[end];
			res = max(res, sum);
			i--; end--;
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> A{ 1,2,3,4,5,6,1 };
	cout << s.maxScore(A, 3);
}