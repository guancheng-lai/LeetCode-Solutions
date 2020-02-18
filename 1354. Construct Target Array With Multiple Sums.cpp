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

class Solution {
public:
	bool isPossible(vector<int>& target) {
		int sum = 0;
		while (sum >= 0) {
			auto max_it = max_element(target.begin(), target.end());
			if (*max_it == 1) return true;
			int idx = distance(target.begin(), max_it); 
			sum = 0;
			
			for (int i = 0; i < target.size(); ++i){
				if (i == idx) continue;
				
				target[idx] -= target[i];
				if (target[idx] < 0) return false;
			}
		}
		
		return false;
	}
};

int main(int argc, char *argv[]) {
	vector<int> v{ 9,3,5 };
	Solution s;
	assert(s.isPossible(v));
}