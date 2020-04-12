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

class Solution {
public:
	vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> P(m);
		for (int i = 0; i < m; ++i) {
			P[i] = i+1;
		}
		
		vector<int> res;
		for (auto q : queries) {
			for (int i = 0; i < m; ++i) {
				if (P[i] == q) {
					res.push_back( i );
					int tmp = P[i];
					P.erase(P.begin() + i);
					P.insert(P.begin(), tmp);
					break;
				}
			}
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	vector<int> queries{3,1,2,1}; // 5
	vector<int> queries{4,1,2,2}; // 4
//	vector<int> queries{7,5,5,8,3}; // 8
	vector<int> res = s.processQueries(queries, 4);	
	for (auto i : res) cout << i << " ";
}