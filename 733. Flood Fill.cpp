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
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int ROW = image.size(), COL = image[0].size();
		int old = image[sr][sc];
		queue< pair<int,int> > q;
		vector< vector<int> > visited(ROW,vector<int>(COL,0));
		q.push( {sr,sc} );
		
		while (!q.empty())
		{
			auto &[r,c] = q.front(); q.pop();
			image[r][c] = newColor;
			
			if (r > 0 && image[r-1][c] == old && visited[r-1][c] == 0) 
			{
				q.push( {r-1,c} );
				visited[r-1][c] = 1;
			}
			
			if (r < ROW-1 && image[r+1][c] == old && visited[r+1][c] == 0) 
			{
				q.push( {r+1,c} );
				visited[r+1][c] = 1;
			}
			
			if (c > 0 && image[r][c-1] == old && visited[r][c-1] == 0) 
			{
				q.push( {r,c-1} );
				visited[r][c-1] = 1;
			}
			
			if (c < COL-1 && image[r][c+1] == old && visited[r][c+1] == 0)
			{
				q.push( {r,c+1} );
				visited[r][c+1] = 1; 
			}
		}
		
		return image;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<int> > image {
		{1,1,1},
		{1,1,0},
		{1,0,1}
	};
	vector< vector<int> > res = s.floodFill(image, 1, 1, 2);	
	for (auto v : res)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}