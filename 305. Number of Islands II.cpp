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
	vector<int> info;
	vector<int> sz;

public:
	UF(int m, int n)
	{
		count = 0;
		info = vector<int>(m * n);
		sz = vector<int>(m * n);

		for (int i = 0; i < m * n; ++i){
			info[i] = -1;
			sz[i] = 0;
		}
	}

	int number() const
	{
		return count;
	}

	int getSize(int i) const
	{
		return sz[root(i)];
	}

	void setSize(int i, int newSize)
	{
		sz[root(i)] = newSize;
	}

	int root(int p) const
	{
		if (p >= info.size() || p < 0) return -1;

		return info[p] != p ? root(info[p]) : info[p];
	}

	bool connected(int p, int q) const 
	{
		int rp = root(p), rq = root(q);
		return rp != -1 && rq != -1 && rp == rq;
	}

	void Union(int p, int q)
	{
		int rp = root(p);
		int rq = root(q);
		if (rp == rq) return;

		if (rp == -1) 
		{
			info[p] = rq;
			sz[rq]++;
		}
		else if (rq == -1)
		{
			info[q] = rp;
			sz[rp]++;
		}
		else 
		{
			int pSize = getSize(rp);
			int qSize = getSize(rq);
			if (pSize > qSize) 
			{
				setSize(rq, 0);
				info[rq] = rp;
				setSize(rp, pSize + qSize);
			}
			else 
			{
				setSize(rp, 0);
				info[rp] = rq;
				setSize(rq, pSize + qSize);
			}
			
			count--;
		}
	}

	void UnionItself(int i)
	{
		info[i] = i;
		setSize(i, 1);
		count++;
	}
};

class Solution 
{
public:
	vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) 
	{
		if ((m == 0 && n == 0) || positions.empty()) return vector<int>();

		vector<int> result(positions.size());
		vector< vector<int> > grid(m, vector<int>(n, 0));
		
		UF uf(m, n);
		
		uf.UnionItself(positions[0][0] * n + positions[0][1]);
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
				uf.Union(myID, myID - n);
				hasNeighbor = true;
			}

			if (c > 0 && grid[r][c-1] == 1) 
			{
				uf.Union(myID, myID - 1);
				hasNeighbor = true;
			}

			if (r < m - 1 && grid[r+1][c] == 1) 
			{
				uf.Union(myID, myID + n);
				hasNeighbor = true;
			}

			if (c < n - 1 && grid[r][c+1] == 1) 
			{
				uf.Union(myID, myID + 1);
				hasNeighbor = true;
			}

			if (!hasNeighbor) 
			{
				result[i] = result[i - 1] + 1;
				uf.UnionItself(myID);
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