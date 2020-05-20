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
	vector<int> peopleIndexes(vector<vector<string>>& fcs) 
	{
		unordered_map<string, unordered_set<int> > mp;
		for (int i = 0; i < fcs.size(); ++i)
		{
			for (const auto &c : fcs[i])
			{
				mp[c].insert(i);
			}
		}
		
		vector<int> res;
		vector< bitset<50000> > vbs;
		for (int i = 0; i < fcs.size(); ++i)
		{
			vbs.resize(fcs[i].size());
			
			int vbsi = 0;
			for (const auto &c : fcs[i]) 
			{
				for (int idx : mp[c])
				{
					if (idx == i) continue;
					vbs[vbsi].set(idx);
				}
				
				vbsi++;
			}
			
			auto bsfinal = std::bitset<50000>{}.set();
			for (auto &bs : vbs) 
			{
				bsfinal &= bs;
			}
			
			if (bsfinal.count() == 0) res.push_back(i);
			
			vbs.clear();
		}
		
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	
}