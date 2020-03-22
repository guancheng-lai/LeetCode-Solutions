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
#include <condition_variable>
#include <future>
#include <fstream>
#include <memory>
#include <limits>
#include <numeric>
using namespace std;

class UF
{
private:
	int count;
	vector<int> info;
	vector<int> sz;

public:
	UF(int len)
	{
		count = 0;
		info = vector<int>(len);
		sz = vector<int>(len);

		for (int i = 0; i < len; ++i){
			info[i] = -1;
			sz[i] = 0;
		}
	}

	int numberOfUnion() const
	{
		return count;
	}

	int getSizeAt(int i) const
	{
		return sz[root(i)];
	}

	void setSizeAt(int i, int newSize)
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

	void unite(int p, int q)
	{
		int rp = root(p);
		int rq = root(q);
		if (rp == rq && rp != -1) return;

		if (rp == rq && rp == -1)
		{
			info[q] = p;
			info[p] = p;
			sz[p] = 2;
			count++;
		}
		else if (rp == -1) 
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
			int pSize = getSizeAt(rp);
			int qSize = getSizeAt(rq);
			if (pSize > qSize) 
			{
				setSizeAt(rq, 0);
				info[rq] = rp;
				setSizeAt(rp, pSize + qSize);
			}
			else 
			{
				setSizeAt(rp, 0);
				info[rp] = rq;
				setSizeAt(rq, pSize + qSize);
			}
			
			count--;
		}
	}

	void uniteOne(int i)
	{
		info[i] = i;
		setSizeAt(i, 1);
		count++;
	}
	
	void printUFInfo() {
		cout << endl;
		for (auto i : info) {
			cout << i << " ";
		}
		cout << endl;
	}
	
	void printUFSize() {
		cout << endl;
		for (auto i : sz) {
			cout << i << " ";
		}
		cout << endl;
	}
	
	vector<int> getUFInfo() const 
	{
		return info;
	}
	
	vector<int> getUFSize() const 
	{
		return sz;
	}
};

class Solution {
public:
	bool hasValidPath(vector<vector<int>> grid) {
		size_t numRows = grid.size();
		size_t numCols = grid[0].size();
        if (numRows == numCols && numRows == 1) return true;
		UF uf(numRows * numCols);
		
		for (int r = 0; r < numRows; ++r) {
			for (int c = 0; c < numCols; ++c) {
				switch (grid[r][c]) 
				{
					case 1:
						if (c > 0 && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) {
							uf.unite(r*numCols + c, r*numCols + c - 1);
						}
						
						if (c < numCols-1 && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
							uf.unite(r*numCols + c, r*numCols + c + 1);
						}
						break;
					case 2:
						if (r > 0 && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) {
							uf.unite(r*numCols + c, (r-1)*numCols + c);
						}
						
						if (r < numRows-1 && (grid[r+1][c] == 2 || grid[r+1][c] == 5 || grid[r+1][c] == 6)) {
							uf.unite(r*numCols + c, (r+1)*numCols + c);
						}
						break;
					case 3:
						if (c > 0 && (grid[r][c-1] == 4 || grid[r][c-1] == 6 || grid[r][c-1] == 1)) {
							uf.unite(r*numCols + c, r*numCols + c - 1);
						}
						
						if (r < numRows-1 && (grid[r+1][c] == 5 || grid[r+1][c] == 6 || grid[r+1][c] == 2)) {
							uf.unite(r*numCols + c, (r+1)*numCols + c);
						}
						break;
					case 4:
						if (r < numRows-1 && (grid[r+1][c] == 5 || grid[r+1][c] == 6 || grid[r+1][c] == 2)) {
							uf.unite(r*numCols + c, (r+1)*numCols + c);
						}
						
						if (c < numCols-1 && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
							uf.unite(r*numCols + c, r*numCols + c + 1);
						}
						
						break;
					case 5:
						if (c > 0 && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) {
							uf.unite(r*numCols + c, r*numCols + c - 1);
						}
						
						if (r > 0 && (grid[r-1][c] == 2 || grid[r-1][c] == 3 || grid[r-1][c] == 4)) {
							uf.unite(r*numCols + c, (r-1)*numCols + c);
						}
						break;
					case 6:
						if (c < numCols-1 && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
							uf.unite(r*numCols + c, r*numCols + c + 1);
						}
						
						if (r > 0 && (grid[r-1][c] == 3 || grid[r-1][c] == 4 || grid[r-1][c] == 2)) {
							uf.unite(r*numCols + c, (r-1)*numCols + c);
						}
						break;
					default:
						break;
				}
				
				// uf.printUFInfo();
				// cout << endl;
			}
		}
		
		return uf.connected(0, numRows * numCols - 1);
	}
	
};

int main(int argc, char *argv[]) {
	Solution s;
	if (s.hasValidPath
	(
		{
//			{2,4,3},{6,5,2}
//			{1,2,1},{1,2,1}
//			{1,1,2}
			{1,1,1,1,1,1,3}
		}
	)){
		cout << "YES" << endl;
	}
	
}