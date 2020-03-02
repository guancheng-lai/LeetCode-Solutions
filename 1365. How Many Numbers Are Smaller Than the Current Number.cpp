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
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		map<int, int> m;
		for (auto i : nums) m[i]++;
		
		vector<int> result(nums.size(), 0);
		
		for (int i = 0; i < nums.size(); ++i) {
			for (auto [k,v] : m) {
				if (k == nums[i]) break;
				
				result[i] += v;
			}
		}
		
		return result;
	}

int main(int argc, char *argv[]) {
	vector<int> v{8,1,2,2,3};
	vector<int> res = smallerNumbersThanCurrent(v);
	for (auto i : res ) cout << i << " ";
}