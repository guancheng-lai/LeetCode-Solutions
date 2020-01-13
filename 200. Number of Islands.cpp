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

class UF 
{
private:	
	int count;
	int col;
	vector<int> info;

public:
	UF(vector<vector<char> > const &grid) 
	{
		count = 0;
		
		size_t numRows = grid.size();
		size_t numCols = grid[0].size();
		col = numCols;
		info = vector<int>(numRows * numCols, -1);
		
		for (int r = 0; r < numRows; ++r) {
			for (int c = 0; c < numCols; ++c) {
				if (grid[r][c] == '1') {
					int id = r * numCols + c;
					info[id] = id;
				}
				else {
					count++;
				}
			}
		}
	}

	void printInfo() const 
	{
		int num = 0;
		for (auto &i : info) {
			cout << std::fixed << std::setw(3) << i << " ";
			num++;
			if (num == col) { 
				cout << endl;
				num = 0;
			}
		}
		cout << "Count = " << count << endl << endl;
	}
	
	int size() const
	{
		return info.size() - count;
	}

	int root(int p)
	{
		if (p >= info.size()) return -1;
		
		return info[p] != p ? root(info[p]) : info[p];
	}

	bool connected(int p, int q) 
	{
		return root(p) == root(q);
	}

	void Union(int p, int q) 
	{
		int rp = root(p);
		int rq = root(q);
		if (rp != -1 && rq != -1 && rp != rq) {
			info[rq] = rp;
			count++;
		}
	}
};

class Solution {
public:
	// Union Find Approach
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		size_t numRows = grid.size();
		size_t numCols = grid[0].size();
		
		UF uf(grid);
		// uf.printInfo();
				
		for (int r = 0; r < numRows; ++r) {
			for (int c = 0; c < numCols; ++c) {
				// cout << "r=" << r << " c=" << c << endl;
				if (grid[r][c] == '1') {
					int myID = r * numCols + c;
					
					if (r < numRows - 1&& grid[r + 1][c] == '1') {    
						int neighborID = myID + numCols;
						uf.Union(myID, neighborID);
						// uf.printInfo(); 
					}
					
					if (c < numCols - 1 && grid[r][c + 1] == '1') {
						int neighborID = myID + 1;
						uf.Union(myID, neighborID);
						// uf.printInfo();
					}
				}
			}
		}
		
		return uf.size();
	}
	
	
	/*      
	// Searching Approach
	
	void searching (int i, int j, const vector<vector<char>>& grid, vector<vector<int>>& revealed) {
		revealed[i][j] = 1;
		
		if (i > 0 && grid[i - 1][j] == 49 && revealed[i - 1][j] == 0) {
			searching(i - 1, j, grid, revealed);
		}
	
		if (i < grid.size() - 1 && grid[i + 1][j] == 49 && revealed[i + 1][j] == 0) {
			searching(i + 1, j, grid, revealed);
		}
		
		if (j > 0 && grid[i][j - 1] == 49 && revealed[i][j - 1] == 0) {
			searching(i, j - 1, grid, revealed);
		}
		
		if (j < grid[0].size() - 1 && grid[i][j + 1] == 49 && revealed[i][j + 1] == 0) {
			searching(i, j + 1, grid, revealed);
		}
	}
	
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0) return 0;
		
		vector<vector<int>> revealed(grid.size(), vector<int>(grid[0].size(), 0));
		int islands(0);
		
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 49 && revealed[i][j] == 0) {
					++islands;
					searching(i, j, grid, revealed);
				}  
			}
		}
		
		return islands;
	}
	*/
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<char> > grid
	{
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};

	assert(s.numIslands(grid) == 3);
	
	vector< vector<char> > grid2
	{
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	assert(s.numIslands(grid2) == 1);
}