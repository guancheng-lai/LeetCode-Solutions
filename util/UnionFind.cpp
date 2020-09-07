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

class UnionFind {
public:
	vector<int> parent;
	vector<int> size;
	int n;
	int setCount;
	
public:
	UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}
	
	UnionFind(const UnionFind& _uf) : parent(_uf.parent), size(_uf.size), n(_uf.n), setCount(_uf.setCount) {}
	
	int root(int x) {
		return parent[x] == x ? x : parent[x] = root(parent[x]);
	}
	
	void unite(int x, int y) {
		if (size[x] < size[y]) {
			swap(x, y);
		}
		parent[y] = x;
		size[x] += size[y];
		--setCount;
	}
		
	bool findAndUnite(int x, int y) {
		int parentX = root(x);
		int parentY = root(y);
		if (parentX != parentY) {
			unite(parentX, parentY);
			return true;
		}
		return false;
	}
};

int main(int argc, char *argv[]) {
	UnionFind uf(10);
	uf.unite(2, 5);
	cout << uf.root(2) << endl;
	cout << uf.root(5) << endl;
}