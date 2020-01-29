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

class TimeMap {
private:
	unordered_map<string, vector< pair<string, int> > > info;
	
public:
	/* Initialize your data structure here. */
	TimeMap() {
		
	}
	
	void set(string key, string value, int timestamp) {
		info[key].push_back({value,timestamp});
	}
	
	string get(string key, int timestamp) {
		for (auto rit = info[key].rbegin(), end = info[key].rend(); rit != end; rit++) {
			if ((*rit).second <= timestamp) {
				return (*rit).first;
			}
		}
		
		return "";
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(int argc, char *argv[]) {
	TimeMap* obj = new TimeMap();
	obj->set("foo","bar",1);
	string param_2 = obj->get("foo",1);
	cout << param_2 << endl;
	param_2 = obj->get("foo",3);
	cout << param_2 << endl;
	
	obj->set("foo","bar2",4);
	
	param_2 = obj->get("foo",4);
	cout << param_2 << endl;
	param_2 = obj->get("foo",5);
	cout << param_2 << endl;
}