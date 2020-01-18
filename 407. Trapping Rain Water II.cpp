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

struct Point {
	int row;
	int col;
	int height;
	Point(int _row, int _col, int _height) : row(_row), col(_col), height(_height) {}
};

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.size() <= 1 || heightMap[0].size() <= 1) { return 0; }

		auto myComp = [](const Point& p1, const Point& p2) { return p1.height > p2.height; };
		priority_queue< Point, vector<Point>, decltype(myComp)> pq(myComp);

		size_t numRows = heightMap.size();
		size_t numCols = heightMap[0].size();
		vector< vector<int> > visited(numRows, vector<int>(numCols, 0));

		for (int r = 0; r < numRows; ++r) {
			pq.push( Point(r,0, heightMap[r][0]) );
			visited[r][0] = 1;
		}

		for (int r = 0; r < numRows; ++r) {
			pq.push( Point(r,numCols - 1, heightMap[r][numCols - 1]) );
			visited[r][numCols - 1] = 1;
		}

		for (int c = 1; c < numCols - 1; ++c) {
			pq.push( Point(0, c, heightMap[0][c]) );
			visited[0][c] = 1;
		}

		for (int c = 1; c < numCols - 1; ++c) {
			pq.push( Point(numRows - 1, c, heightMap[numRows - 1][c]) );
			visited[numRows - 1][c] = 1;
		}

		int result(0);
		int currMax(0);
		while (!pq.empty()) {
			Point curr = pq.top(); pq.pop();
			// cout << curr.row << "-" << curr.col << endl;
			visited[curr.row][curr.col] = 1;
			if (curr.height > currMax) {
				currMax = curr.height;
			}
			else {
				result += (currMax - curr.height);
			}

			if (curr.row < numRows - 1 && visited[curr.row + 1][curr.col] == 0) {
				pq.push( Point(curr.row + 1, curr.col, heightMap[curr.row + 1][curr.col]) );
				visited[curr.row + 1][curr.col] = 1;
			}

			if (curr.row > 0 && visited[curr.row - 1][curr.col] == 0) {
				pq.push( Point(curr.row - 1, curr.col, heightMap[curr.row - 1][curr.col]) );
				visited[curr.row - 1][curr.col] = 1;
			}

			if (curr.col < numCols - 1 && visited[curr.row][curr.col + 1] == 0) {
				pq.push( Point(curr.row, curr.col + 1, heightMap[curr.row][curr.col + 1]) );
				visited[curr.row][curr.col + 1] = 1;
			}

			if (curr.col > 0 && visited[curr.row][curr.col - 1] == 0) {
				pq.push( Point(curr.row, curr.col - 1, heightMap[curr.row][curr.col - 1]) );
				visited[curr.row][curr.col - 1] = 1;
			}
		}

		return result;
	}
};

int main(int argc, char *argv[]) {
	vector< vector<int> > vv
	{
		{1,4,3,1,3,2},	
		{3,2,1,3,2,4},
		{2,3,3,2,3,1}
	};
	
	Solution s;
	cout << s.trapRainWater(vv) << " == 4";
}