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
private:
    struct coord {
        int r;
        int c;
        coord() { r=0; c=0; }
        coord(int _r, int _c) : r(_r), c(_c) {}
    };
    
    
public:
    int countServers(vector<vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        UF uf(m*n);
        
        for (int r=0; r<m; r++) {
            for (int c=0; c<n; c++) {
                if (grid[r][c] == 1) {
                    // q.push(coord(r,c));
					if (uf.getUFInfo()[r*n + c] == -1){ 
						uf.uniteOne(r * n + c);
					}
                    
                    for (int i=c+1; i<n; ++i) {
                        if (grid[r][i] == 1 && !uf.connected(r*n + i, r*n + c)) {
							uf.unite(r*n + c, r*n + i); 
						}
                    }
                    
                    for (int i=r+1; i<m; ++i) {
                        if (grid[i][c] == 1 && !uf.connected(i*n + c, r*n + c)) { 
							uf.unite(r*n + c, i*n + c); 
						}
                    }
                }   
            }
        }
        
        int result(0);
        vector<int> uf_sz = uf.getUFSize();
        for (auto i : uf_sz) {
            if (i > 1) {
                result += i;
            }
        }
        
        return result;
    }
	
	// Faster Approach
	/*
	class Solution {
	public:
		int countServers(vector<vector<int>>& grid) {
			size_t m = grid.size();
			size_t n = grid[0].size();
			
			vector<int> row(m,0);
			vector<int> col(n,0);
			
			for (int r=0; r<m; r++) {
				for (int c=0; c<n; c++) {
					if (grid[r][c] == 1) {
						row[r]++;
						col[c]++;
					}
				}
			}
			
			int result(0);
			for (int r=0; r<m; r++) {
				for (int c=0; c<n; c++) {
					if (grid[r][c] == 1 && (row[r] > 1 || col[c] > 1)) {
						result++;
					}
				}
			}
			
			return result;
		}
	};
	*/
};


int main(int argc, char *argv[]) {
	vector< vector<int> > grid
	{
		{1,0},
		{1,1}
	};
	
	Solution s;
	cout << s.countServers(grid);	
}