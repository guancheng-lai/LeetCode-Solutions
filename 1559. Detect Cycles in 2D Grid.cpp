class Solution {
public:    
	vector< vector<int> > visited;
	
	bool isPrev(int r1, int c1, int r2, int c2) {
		return r1 == r2 && c1 == c2;
	}
	
	bool containsCycle(vector<vector<char>>& grid) {
		int ROW = grid.size(), COL = grid[0].size();
		visited.assign(ROW, vector<int>(COL, 0));
		for (int R = 0; R < ROW; ++R) {
			for (int C = 0; C < COL; ++C) {
				if (visited[R][C] == 1) continue;
				visited[R][C] = 1;
				char key =  grid[R][C];
				set< pair<int,int> > s; 
				queue< array<int, 4> > q; q.push( {R,C,-1,-1} );
				
				while (!q.empty()) {
					array<int, 4> info = q.front(); q.pop();
					int r = info[0], c = info[1], lastr = info[2], lastc = info[3];
					visited[r][c] = 1;
					if (s.find( {r,c} ) != s.end()) return true;
					s.insert( {r,c} );
					
					if (r > 0 && !isPrev(r-1, c, lastr, lastc) && grid[r-1][c] == key) q.push( {r-1,c,r,c} );
					if (r < ROW-1 && !isPrev(r+1, c, lastr, lastc) && grid[r+1][c] == key) q.push( {r+1,c,r,c} );
					if (c > 0 && !isPrev(r, c-1, lastr, lastc) && grid[r][c-1] == key) q.push( {r,c-1,r,c} );
					if (c < COL-1 && !isPrev(r, c+1, lastr, lastc) && grid[r][c+1] == key) q.push( {r,c+1,r,c} );
				}
			}
		}
		
		
		return false;
	}
};