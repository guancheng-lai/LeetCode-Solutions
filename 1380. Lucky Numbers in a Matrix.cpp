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
	vector<int> luckyNumbers (vector<vector<int>>& matrix) {
		if (matrix.size() == 0) return vector<int>();
		size_t nr = matrix.size(), nc = matrix[0].size();
		vector<int> result;
		
		for (int r = 0; r < nr; ++r) {
			auto minIt = min_element( matrix[r].begin(), matrix[r].end() );
			int minIdx = distance(matrix[r].begin(), minIt);
			int minVal = *minIt;
			bool isLarge = true;
			for (int i = 0; i < nr; ++i) {
				if (matrix[i][minIdx] > minVal) {
					isLarge = false;
					break;
				}
			}
			
			if (isLarge) result.push_back(minVal);
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<int> > matrix
	{
		{3,7,8},
		{9,11,13},
		{15,16,17}
	};
	
	vector<int> result = s.luckyNumbers(matrix);
	for (auto i : result) cout << i << " ";
}