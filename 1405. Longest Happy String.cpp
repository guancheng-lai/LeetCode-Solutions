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
	string longestDiverseString(int A, int B, int C) {
		priority_queue< pair<int,char> > pq;
		if (A > 0) pq.push({A,'a'});
		if (B > 0) pq.push({B,'b'});
		if (C > 0) pq.push({C,'c'});
		
		string res("");
		
		auto [v,c] = pq.top(); pq.pop();
		if (v >= 2) {
			res += c; res += c;
			if (v-2 > 0) pq.push({v-2,c});
		}
		else if (c == 1) {
			res += c;
			
			auto [v2,c2] = pq.top(); pq.pop();
			res += c2; v2--;
			if (v2 > 0) pq.push({v2,c});
		}
		
		while (!pq.empty()) {
			auto p = pq.top(); pq.pop();
			if (res[res.size()-1] == p.second && res[res.size()-2] == p.second) {
				if (pq.empty()) break;
				auto p2 = pq.top(); pq.pop();
				res += p2.second; p2.first--;
				
				pq.push(p); 
				if (p2.first > 0) pq.push(p2);
			}
			else if (res[res.size()-1] == p.second) {
				res += p.second;
				p.first--;
				if (v-1 > 0) pq.push(p);
			}
			else {
				int count(0);
				while (p.first > 0 && count++ < 2) {
					res += p.second; p.first--;
				}
				if (p.first > 0) pq.push(p);
			}
		}
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	cout << s.longestDiverseString(1, 1, 7);
//	cout << s.longestDiverseString(2, 2, 1);
//	cout << s.longestDiverseString(7, 1, 0);
//	cout << s.longestDiverseString(1, 3, 5);
	cout << s.longestDiverseString(0, 8, 11);
}