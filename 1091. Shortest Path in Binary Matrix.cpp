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
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid.size() == 0) return -1;
		if (grid.size() == 1) return 1;
		if (grid[0][0] == 1) return -1;
		if (grid.back().back() == 1) return -1;
		
		//     tuple<row, col, pathLen>
		queue< tuple<int, int, int> > q;
		q.push( {0,0,1} );
		// unordered_set< pair<int, int> > accessed;
		vector<vector<int>> accessed(grid.size(), vector<int>(grid[0].size(), 0));
		// accessed.insert( {0,0} );
		accessed[0][0] = 1;

		
		while (!q.empty()) {
			auto [r, c, len] = q.front(); q.pop();
			// cout << r << "," << c << "," << len << "\n";
		  
			if (r == grid.size() - 1&& c == grid[0].size() - 1) {
				return len;
			}
		  
			if ( r < grid.size() - 1 ) {
			  
				if (grid[r+1][c] == 0 && accessed[r+1][c] == 0) {
					q.push( {r+1,c,len+1} );   
					// accessed.insert( {r+1,c} );
					accessed[r+1][c] = 1;
				}
				
				if ( c < grid[0].size() - 1 && grid[r+1][c+1] == 0 && accessed[r+1][c+1] == 0) {
					q.push( {r+1,c+1,len+1} );
					accessed[r+1][c+1] = 1;
				}
				
				if ( c > 0 && grid[r+1][c-1] == 0 && accessed[r+1][c-1] == 0) {
					q.push( {r+1,c-1,len+1} );
					accessed[r+1][c-1] = 1;
				}
			}
			
			if ( r > 0 ) {
				if (grid[r-1][c] == 0 && accessed[r-1][c] == 0) {
					q.push( {r-1,c,len+1} ); 
					accessed[r-1][c] = 1;
				}
				
				if ( c < grid[0].size() - 1 && grid[r-1][c+1] == 0 && accessed[r-1][c+1] == 0) {
					q.push( {r-1,c+1,len+1} );
					accessed[r-1][c+1] = 1;
				}
				
				if ( c > 0 && grid[r-1][c-1] == 0 && accessed[r-1][c-1] == 0) {
					q.push( {r-1,c-1,len+1} );
					accessed[r-1][c-1] = 1;
				}
				
			} 
		  
			if (c < grid[0].size() - 1 && grid[r][c+1] == 0 && accessed[r][c+1] == 0) {
				q.push( {r,c+1,len+1} );
				accessed[r][c+1] = 1;
			}
			
			if (c > 0 && grid[r][c-1] == 0 && accessed[r][c-1] == 0) {
				q.push( {r,c-1,len+1} );
				accessed[r][c-1] = 1;
			}
			
		}
		
		return -1;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	vector< vector<int> > grid {{0,0,0},{1,1,0},{1,1,0}};
	cout << solution.shortestPathBinaryMatrix(grid);
}