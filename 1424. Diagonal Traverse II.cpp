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
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		vector< vector<int> > preProcessing;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < nums[i].size(); ++j) {
				preProcessing.push_back(vector<int>());
				preProcessing[i+j].insert( preProcessing[i+j].begin(),nums[i][j] );
			}
		}
		
		vector<int> result;
		for (auto &v: preProcessing)
			for (auto i : v)
				result.push_back(i);

		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<int> > A{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	
//	vector< vector<int> > A{
//		{6},
//		{8},
//		{6,1,6,16}	
//	};
	
	vector<int> res = s.findDiagonalOrder(A);
	for (auto i : res) cout << i << " ";
}