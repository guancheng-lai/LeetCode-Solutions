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

class UF {
private:  
	vector<int> info;
public:
	UF(int sz) { info.resize(sz, -1); }
	
    vector<int> getInfo() const { return this->info; }
	
	int root(int p) {
		if (p < 0 || info[p] == -1) return -1;
		
		return info[p] == p ? info[p] : root(info[p]);
	}
	
	bool isConnected(int p, int q) {
        int rp = root(p), rq = root(q);
		return rp == rq && rp != -1;
	}
	
	void unite(int p, int q) {
		int rp = root(p);
		int rq = root(q);
		
		if (rp == rq && rp == -1) {
			info[p] = p;
			info[q] = p;
		}   
		else if (rp == -1) {
			info[p] = rq;
		}
		else if (rq == -1) {
			info[q] = rp;
		}
		else {
			info[rq] = rp;
		}
	}
};

class Solution {
public:
	bool equationsPossible(vector<string>& equations) {
		/*
		Runtime: 4 ms, faster than 97.52% of C++ online submissions for Satisfiability of Equality Equations.
		Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Satisfiability of Equality Equations.
		*/
		
		size_t len = equations.size();
		UF uf(26);
		
		for (int i = 0; i < len; ++i) {
			if (equations[i][1] == '!') continue;
			int p = equations[i][0] - 'a';
			int q = equations[i][3] - 'a';
			uf.unite(p, q);
		}
		
		for (int i = 0; i < len; ++i) {
			if (equations[i][1] == '=') continue;
			int p = equations[i][0] - 'a';
			int q = equations[i][3] - 'a';
			if (p == q) return false;
			
			if (uf.isConnected(p, q)) {
				return false;
			}
		}
		
		return true;
	}
};

int main(int argc, char *argv[]) {
	vector<string> vs{
		"a==b",
		"b==c",
		"a==c"
	}; // TRUE
	
	vector<string> vs2{
		"a==b",
		"b!=c",
		"c==a"
	}; // FALSE
	
	vector<string> vs3{	
		"c==c",
		"b==d",
		"x!=z"
	}; //TRUE
	
	vector<string> vs4{	
		"a==b",
		"b!=a"
	}; // FALSE
	
	vector<string> vs5{		
		"b==a",
		"a==b"
	}; // TRUE
	
	vector<string> vs6 {
		"a!=a"
	}; // FALSE
	
	vector<string> vs7 {
		"c==c",
		"f!=a",
		"f==b",
		"b==c"
	}; //TRUE
	
	Solution s;
	bool b = s.equationsPossible(vs7);
	if (b) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}