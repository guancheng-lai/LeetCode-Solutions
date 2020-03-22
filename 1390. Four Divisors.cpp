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
	unordered_map<int,pair<int,int>> memo;
	
	pair<int,int> findD(int num) {
		if (num == 1) return {1,1};
		if (num == 2) return {2,3};
		
		if (memo.find(num) != memo.end()) return memo[num];
		int result(2);
		int sum = 1 + num;
		for (int i = 2; i <= sqrt(num); ++i) {
			if (num % i == 0) {
				if (i == num / i) {
					result++;    
					sum += i;
				}
				else {
					result += 2;
					sum += (i + num/i);
				}
				
				if (result > 4) {
					memo[num] = {result,sum};
					return {result,sum};
				}
			}
		}
		memo[num] = {result,sum};
		return {result,sum};
	}
	
	int sumFourDivisors(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int result(0);
		for (auto i : nums) {
			auto [r,s] = findD(i);
			if (r == 4) {
				result += s;
			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> arr{21,4,7};
	cout << s.sumFourDivisors(arr);	
}