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
	int _count;
	
public:	
	UF(int size) : _count(size) 
	{
		this->_info.resize(size);
		for (int i = 0; i < size; ++i) this->_info[i] = i;
//		idx 0 1 2 3 4 5
//		val 0 1 2 3 4 5
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
		_info[rq] = rp;
		_count--;
	}
	
	void printinfo() {
		cout << endl;
		for (auto i : _info) cout << i << " ";
		cout << endl;
	}
};


class Weighted_UF 
{
private:
	vector<int> _info;
	vector<int> _size;
	int _count;
	
public:	
	Weighted_UF(int size) : _count(size) 
	{
		this->_info.resize(size);
		for (int i = 0; i < size; ++i) this->_info[i] = i;
		
		this->_size.resize(size, 1);
	} 
	
	int root(int p) 
	{
		while (_info[p] != p) p = _info[p];
		
		return _info[p];
	}
	
	int root_path_compression(int p) 
	{		
		int root = root(p);
		
		while (p != _info[p]) {
			int newp = _info[p];
			_info[p] = root;
			p = newp;
		}		
		
		return root;
	}
	
	bool isConnected(int p, int q) 
	{
		return p == q || root(p) == root(q);
	}
	
	void unite(int p, int q) 
	{
		int rp = root(p), rq = root(q);
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
	}
	
	void printinfo() const
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

};


int main(int argc, char *argv[]) {
//	Weighted_UF wuf(10);
//	wuf.uniteOne(3);
//	wuf.uniteOne(4);
//	wuf.unite(3,4);
//	wuf.print_info();
//	wuf.print_size();
//	UF uf(6);
//	uf.unite(2, 3);
//	uf.printinfo();
//
//	uf.unite(2, 1);
//	uf.printinfo();
//
//	uf.unite(3, 4);
//	uf.printinfo();
//
//	uf.unite(4, 5);	
//	uf.printinfo();
//	
//	uf.unite(0, 2);
//	uf.printinfo();
//	cout << "----------\n";
	Weighted_UF wuf(6);
	wuf.unite(2, 3);
	wuf.printinfo();

	wuf.unite(2, 1);
	wuf.printinfo();

	wuf.unite(3, 4);
	wuf.printinfo();

	wuf.unite(4, 5);	
	wuf.printinfo();
		
	wuf.unite(0, 2);
	wuf.printinfo();
	
}