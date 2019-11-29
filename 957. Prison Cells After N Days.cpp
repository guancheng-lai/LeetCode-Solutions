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
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		if (N == 0) return cells;
		size_t len = cells.size();
		int idx = 0;
		// cout << idx++ << ": ";
		// for (auto &i : cells) {
		//     cout << i << " ";
		// }
		// cout << endl;
		
		N = N % 14;
		N = N == 0 ? 14 : N;
		for (int d = 0; d < N; ++d) {
			vector<int> nextDay(cells);
			nextDay[0] = 0;
			nextDay[len - 1] = 0;
			
			for (int i = 1; i < len - 1; ++i) {
				if (cells[i - 1] == cells[i + 1]) {
					
					nextDay[i] = 1;
				}
				else {
					nextDay[i] = 0;
				}   
			}
			
			cells = nextDay;
			// cout << idx++ << ": ";
			// for (auto &i : cells) {
			//     cout << i << " ";
			// }
			// cout << endl;
		}
		
		return cells;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	vector<int> v{ 1,0,0,1,0,0,1,0 };
	v = solution.prisonAfterNDays(v, 1000000000);
	for (auto &i : v) {
		cout << i << " ";
	}
}