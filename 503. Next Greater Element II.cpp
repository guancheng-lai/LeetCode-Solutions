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
private:
	template <typename T1, typename T2>
	void printMap(const map<T1, T2> &m) {
		cout << "MAP: ";
		for (auto &it : m) {
			cout << it.first << "-" << it.second << " ";
		}
		cout << "\n------------\n";
	}

	
	template <typename T1, typename T2>
	void printStackOfPair(stack< pair<T1,T2> > s) {
		cout << "TOP-> ";
		while (!s.empty()) {
			auto [t1, t2] = s.top(); s.pop();
			cout << t1 << "-" << t2 << " ";
		}
		cout << "->BOTTOM\n-------------\n";
	}
	
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		size_t len = nums.size();
		
		//     pair<idx, num>
		stack< pair<int, int> > smaller;
		map<int, int> mp;
		vector<int> result(len);
		
		for (int times = 0; times != 2; times++) {
			for (int i = 0; i != len; ++i) {
				while ( !smaller.empty() && smaller.top().second < nums[i] ) {
					auto [idx, num] = smaller.top(); smaller.pop();
					mp[idx] = i;
					//printMap(mp);
				}

				smaller.push( {i, nums[i]} );
				//printStackOfPair(smaller);
			}    
		}
		
		
		for (int i = 0; i != len; ++i) {
			if (mp.count( i ) != 0) {
				result[i] = nums[ mp[i] ];
			}
			else {
				result[i] = -1;
			}
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	vector<int> nums {1,2,1};
	vector<int> res = solution.nextGreaterElements(nums);	
	vector<int> correct {2,-1,2};
	if (res == correct) {
		cout << "Correct\n";
	}
}