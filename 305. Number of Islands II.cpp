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
	vector<int> _info;
	vector<int> _size;
	int _count;
	
public:	
	UF(int m, int n) : _count(0) 
	{
		this->_info.resize(m * n);
		for (int i = 0; i < m * n; ++i) this->_info[i] = i;
		
		this->_size.resize(m * n, 0);
	} 
	
	int root(int p) 
	{
		while (_info[p] != p) p = _info[p];
		
		return _info[p];
	}
	
	bool isConnected(int p, int q) 
	{
		return p == q || root(p) == root(q);
	}
	
	void unite(int p, int q) 
	{
		int rp = root(p), rq = root(q);
		if (rp == rq) return;
		if (_size[rp] != 0 && _size[rq] != 0) _count--;
		
		if (_size[rp] >= _size[rq]) 
		{
			_info[rq] = rp;
			_size[rp] += _size[rq];
			_size[rq] = 0;
		}
		else 
		{
			_info[rp] = rq;
			_size[rq] += _size[rp];
			_size[rp] = 0;
		}
	}
	
	void uniteOne(int p) 
	{
		_size[p] = 1;
		_count++;
	}
	
	void print_info() const
	{
		cout << endl;
		for (auto i : _info) cout << i << " ";	
		cout << endl;
	}
	
	void print_size() const
	{
		cout << endl;
		for (auto i : _size) cout << i << " ";	
		cout << endl;
	}
	
	int number() const {
		return this->_count;
	}
};

class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
		if (m == 0 && n == 0) return vector<int>();
		if (positions.empty()) return vector<int>();

		vector<int> result(positions.size());

		vector< vector<int> > grid(m, vector<int>(n, 0));
		UF uf(m, n);
		uf.uniteOne(positions[0][0] * n + positions[0][1]);
		grid[positions[0][0]][positions[0][1]] = 1; 
		result[0] = 1;

		for (int i = 1, end = positions.size(); i < end; ++i) 
		{
			int r = positions[i][0], c = positions[i][1];
			if (grid[r][c] != 0) 
			{
				result[i] = result[i - 1];
				continue;
			}
			
			grid[r][c] = 1;
			int myID = r * n + c;
			bool hasNeighbor = false;

			if (r > 0 && grid[r-1][c] == 1) 
			{
				uf.unite(myID, myID - n);
				hasNeighbor = true;
			}

			if (c > 0 && grid[r][c-1] == 1) 
			{
				uf.unite(myID, myID - 1);
				hasNeighbor = true;
			}

			if (r < m - 1 && grid[r+1][c] == 1) 
			{
				uf.unite(myID, myID + n);
				hasNeighbor = true;
			}

			if (c < n - 1 && grid[r][c+1] == 1) 
			{
				uf.unite(myID, myID + 1);
				hasNeighbor = true;
			}

			if (!hasNeighbor) 
			{
				result[i] = result[i - 1] + 1;
				uf.uniteOne(myID);
			}
			else 
			{
				result[i] = uf.number();
			}
		}

		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector< vector<int> > testcase1 // 3 * 3
	{
		{0,0},
		{0,1},
		{1,2},
		{2,1}
	};

	vector< vector<int> > testcase2 // 2 * 2
	{
		{0,0},
		{1,1},
		{0,1}
	};

	vector< vector<int> > testcase3 // 3 * 3
	{
		{0,0},
		{1,0},
		{2,0},
		{0,2},
		{1,2},
		{2,2},
		{1,1}
	};

	vector< vector<int> > testcase4 // 3 * 3
	{
		{0,1},
		{1,2},
		{2,1},
		{1,0},
		{0,2},
		{0,0},
		{1,1}
	};

	vector< vector<int> > testcase5 // 3 * 3
	{
		{0,0},
		{0,1},
		{1,2},
		{1,2}
	};

	vector<int> result = s.numIslands2(3, 3, testcase5);
	for (auto &i : result) {
		cout << i << " ";
	}
}