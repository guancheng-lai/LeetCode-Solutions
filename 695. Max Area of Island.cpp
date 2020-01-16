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
private:
	int max = 0;    
public:
	void searching (int i, int j, int &maxArea, const vector<vector<int>>& grid, vector<vector<int>>& revealed) {
		revealed[i][j] = 1;
		++maxArea;
		
		if (i > 0 && grid[i - 1][j] == 1 && revealed[i - 1][j] == 0) {
			searching(i - 1, j, maxArea, grid, revealed);
		}
		
		if (i < grid.size() - 1 && grid[i + 1][j] == 1 && revealed[i + 1][j] == 0) {
			searching(i + 1, j, maxArea, grid, revealed);
		}
		
		if (j > 0 && grid[i][j - 1] == 1 && revealed[i][j - 1] == 0) {
			searching(i, j - 1, maxArea, grid, revealed);
		}
		
		if (j < grid[0].size() - 1 && grid[i][j + 1] == 1 && revealed[i][j + 1] == 0) {
			searching(i, j + 1, maxArea, grid, revealed);
		}
	}
	
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.size() == 0) return 0;
		
		vector<vector<int>> revealed(grid.size(), vector<int>(grid[0].size(), 0));
		
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1 && revealed[i][j] == 0) {
					int maxArea(0); 
					searching(i, j, maxArea, grid, revealed);
					max = maxArea > max ? maxArea : max;
				}  
			}
		}
		
		return max;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<int> > grid
	{
		{1,1,0,0,0},
		{1,1,0,0,0},
		{0,0,0,1,1},
		{0,0,0,1,1}
	};
	
	assert(s.maxAreaOfIsland(grid) == 4);
}