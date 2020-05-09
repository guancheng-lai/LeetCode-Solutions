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
	int maxSumSubmatrix(vector<vector<int>>& mat, int k) 
	{
		int ROW = mat.size(); if (ROW == 0) return 0;
		int COL = mat[0].size(); if (COL == 0) return 0;
		
		int res = INT_MIN;
		for (int leftCol = 0; leftCol < COL; ++leftCol) 
		{
			vector<int> preSum(ROW,0);
			for (int rightCol = leftCol; rightCol < COL; ++rightCol) 
			{
				for (int r = 0; r < ROW; ++r)
				{
					preSum[r] += mat[r][rightCol];
				}
				
				int currSum, currMax = INT_MIN;
				for (int upRow = 0; upRow < ROW; ++upRow)
				{
					currSum = 0;
					for (int downRow = upRow; downRow < ROW; ++downRow)
					{
						currSum += preSum[downRow];
						if (currSum <= k && currSum > currMax)
						{
							currMax = currSum;
						}
					}
				}
				
				if (currMax > res) res = currMax;
			}
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<int> > mat { {1,0,1},{0,-2,3} };
	cout << s.maxSumSubmatrix(mat, 2);
}