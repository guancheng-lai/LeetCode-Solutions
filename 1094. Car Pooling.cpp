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
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		map<int, int> m;
		for (auto &v: trips) {
			m[ v[1] ] += v[0];
			m[ v[2] ] -= v[0];
		}
		
		int curr(0);
		for(auto it : m) {
			curr += it.second;
			if (curr > capacity) return false;
		}
		
		return true;
	}
};

int main(int argc, char *argv[]) {
	vector< vector<int> > vv
	{
		{3,2,7},
		{3,7,9},
		{8,3,9}
	};
	
	Solution s;
	assert(s.carPooling(vv, 11));
}