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
	int findLucky(vector<int>& arr) {
		unordered_map<int,int> m;
		for (auto i : arr) {
			m[i]++;
		}
		
		int maxK = -1;
		for (auto [k,v] : m) {
			if (k == v) {
				if (k > maxK) {
					maxK = k;
				}
			}
		}
		
		return maxK;      
	}
};

int main(int argc, char *argv[]) {
	vector<int> v{ 2,2,3,4 };
	Solution s;
	cout << s.findLucky(v);
}