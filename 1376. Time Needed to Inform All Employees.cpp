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

class Solution {
public:
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		unordered_map<int, vector< pair<int,int> > > m;
		for (int i = 0; i < n; ++i) {
			if (i == headID) continue;
			m[ manager[i] ].push_back( {i,informTime[ manager[i] ]} );
		}
		
		int result(0);
		queue< pair<int,int> > q, q2;
		q.push( {headID,0} );
		while (!q.empty()) {
			q2 = q;
			q = queue<pair<int,int>>();
			
			while (!q2.empty()) {
				auto [managerID,currtime] = q2.front(); q2.pop();

				for (auto [e,t] : m[managerID]) {
					result = max(result, currtime + t);
					q.push( {e,currtime+t} );
				}
			}
		}
		
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> manager{5,9,6,10,-1,8,9,1,9,3,4};
	vector<int> informTime{0,213,0,253,686,170,975,0,261,309,337};
	cout << s.numOfMinutes(11, 4, manager, informTime);
}