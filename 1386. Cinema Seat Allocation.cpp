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
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		int result(0);
		unordered_map<int, unordered_set<int> > row;
		for (int i = 0, i2 = reservedSeats.size(); i < i2; ++i) {
			row[reservedSeats[i][0]].insert( reservedSeats[i][1] );
		}
		
		result += (n - row.size()) * 2;
		
		for (auto &[r,s] : row) {
			if (row.count(r) == 0) result += 2;
			else {
				bool left = true, mid = true, right = true;
				for (int c = 2; c <= 5; ++c) {
					if (row[r].count(c)) {
						left = false;
						break;
					}
				}
				
				for (int c = 4; c <= 7; ++c) {
					if (row[r].count(c)) {
						mid = false;
						break;
					}
				}
				
				for (int c = 6; c <= 9; ++c) {
					if (row[r].count(c)) {
						right = false;
						break;
					}
				}
				
				if (left && mid && right) {
					result += 2;
				}
				else if (!left && !mid && !right){
					
				}
				else {
					result++;
				}

			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
//	vector< vector<int> > r{
//		{2,1},
//		{1,8},
//		{2,6}
//	};
	
	vector< vector<int> > r{
		{1,2},
		{1,3},
		{1,8},
		{2,6},
		{3,1},
		{3,10}
	};
	
	vector< vector<int> > r2{
		{4,7},{4,1},{3,1},{5,9},{4,4},{3,7},{1,3},{5,5},{1,6},{1,8},{3,9},{2,9},{1,4},{1,9},{1,10}		
	};
	
	
	cout << s.maxNumberOfFamilies(5, r2);
}