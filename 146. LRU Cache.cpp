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

class LRUCache {
private:
	list<pair<int, int> > LRU;

	// map< key, list<key,value>::it > >
	unordered_map<int, list< pair<int, int> >::iterator > indexs;
	int MAXSIZE;
	
	void touch(int key) {
		// cout << "Touch " << key << "-" << indexs[key]->second <<endl;
		auto it = indexs[key];
		LRU.emplace_back( make_pair(key, indexs[key]->second) );
		indexs[key] = std::next(LRU.end(), -1);
		LRU.erase(it);
	}
	
// 	void printLRU() {
// 		cout << "LRU = ";
// 		for (auto it = LRU.begin(); it != LRU.end(); it++) {
// 			cout << (*it).first << "-" << (*it).second <<  " ";
// 		}
// 		cout << endl;
// 	}
	
// 	void printMAP() {
// 		cout << "MAP = ";
// 		for (auto it = indexs.begin(); it != indexs.end(); ++it) {
// 			cout << it->first << "->(" << it->second->first << "," << it->second->second << ") ";
// 		}
// 		cout << endl;
// 	}
	
// 	void print() {
// 		printLRU();
// 		printMAP();
// 	}
	
public:
	LRUCache(int capacity): MAXSIZE(capacity) { }
	
	int get(int key) {
		// cout << "Get: " << key << endl;
		if (indexs.count(key) == 0) { return -1; }
		int result = indexs[key]->second;
		touch(key);
		// print();
		return result;
	}
	
	void put(int key, int value) {
        // cout << "Put: " << key << "-" << value << endl;
		if (indexs.count(key) != 0) {
			touch(key);
			auto it = std::next(LRU.end(), -1);
			it->second = value;
		}
		else if (LRU.size() == MAXSIZE) {
			int begin_k = LRU.begin()->first, begin_v = LRU.begin()->second;
			LRU.erase( indexs[begin_k] );
			indexs.erase( begin_k );
			
			LRU.emplace_back( make_pair(key, value) );
			indexs[key] = std::next(LRU.end(), -1);
		}
		else {
			LRU.emplace_back( make_pair(key, value) );
			indexs[key] = std::next(LRU.end(), -1);
		}
		// print();
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char *argv[]) {
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	assert(cache.get(1) == 1);     	// returns 1
	cache.put(3, 3);    			// evicts key 2
	assert(cache.get(2) == -1);     // returns -1 (not found)
	cache.put(4, 4);    			// evicts key 1
	assert(cache.get(1) == -1);     // returns -1 (not found)
	assert(cache.get(3) == 3);      // returns 3
	assert(cache.get(4) == 4);      // returns 4
}