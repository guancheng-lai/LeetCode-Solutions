class Solution {
public:
	int ROW, COL;
	vector< vector<int> > visited;
	
	void visit(const vector< vector<int> >& grid, int r, int c) {
		if (r < 0 || c < 0 || r >= ROW || c >= COL || visited[r][c] || grid[r][c] == 0) return;
		
		visited[r][c] = true;
		visit(grid, r+1, c);
		visit(grid, r-1, c);
		visit(grid, r, c+1);
		visit(grid, r, c-1);
	}
	
	int countIslands(const vector< vector<int> >& grid) {
		int res = 0;
		visited.assign(ROW, vector<int>(COL, 0));
		for (int r = 0; r < ROW; ++r) {
			for (int c = 0; c < COL; ++c) {
				if (!visited[r][c] && grid[r][c] == 1) {
					res++;
					visit(grid, r, c);
				}
			}
		}
		return res;
	}
	
	int minDays(vector<vector<int>>& grid) {
		this->ROW = grid.size();
		this->COL = grid[0].size();
		if (countIslands(grid) != 1) return 0;
		
		for (int r = 0; r < ROW; r++) {
			for (int c = 0; c < COL; ++c) {
				if (grid[r][c] == 1) {
					grid[r][c] = 0;
					if (countIslands(grid) != 1) {
						return 1;
					}
					grid[r][c] = 1;
				}
			}
		}
		
		return 2;
	}
};