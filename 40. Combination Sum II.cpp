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
	vector< vector<int> > result;
	
	void helper(vector<int>& candidates, vector<int> &inprogress, int target, int idx) {
		if (target < 0) { return; }
		else if (target == 0) { 
			result.push_back(inprogress);
		}
		else {
			for (int i = idx; i < candidates.size(); ++i) {
				if (i > idx && candidates[i - 1] == candidates[i]) { continue; }
				
				inprogress.push_back(candidates[i]);
				helper(candidates, inprogress, target - candidates[i], i + 1);
				inprogress.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty()) return vector< vector<int> >();
		
		sort(candidates.begin(), candidates.end());

		if (target < candidates[0]) return vector< vector<int> >();
		if (target == candidates[0]) return { {target} };
		
		vector<int> inprogress;
		helper(candidates, inprogress, target, 0);
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
    vector<int> candidates{ 10,1,2,7,6,1,5 };
	vector< vector<int> > vv = s.combinationSum2(candidates, 8);
	for (auto &v : vv) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}