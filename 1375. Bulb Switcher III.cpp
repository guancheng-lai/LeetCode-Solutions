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
	// Union Find solution
    int numTimesAllBlue1(vector<int>& light) {
        int n = light.size();
		int result(0);
		UF uf(n);
		for (int i = 0; i < n; ++i) {
			int l = light[i]-1;
			uf.uniteOne(l);
			if (uf.root(l-1) != -1) {
				uf.unite(l-1,l);
			}
			
			if (uf.root(l+1) != -1) {
				uf.unite(l+1,l);
			}
			
			if (uf.numberOfUnion() == 1 && uf.root(0) != -1){
				result++;
			}
		}
		
		return result;
    }
	
	// Check missed number solution
	int numTimesAllBlue2(vector<int>& light) {
		int right = 0;
		int result = 0;
		for (int i = 0; i < light.size(); ++i) {
			right = max(right, light[i]);
			if (right == i+1) result++;
		}
			
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> li{3,2,4,1,5};
	cout << s.numTimesAllBlue1(li) << endl;	
	cout << s.numTimesAllBlue2(li) << endl;	

}