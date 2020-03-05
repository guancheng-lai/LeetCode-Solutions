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
	string rankTeams(vector<string>& votes) {
		if (votes.size() == 1) return votes[0];
		
		int numTeams = votes[0].size();
		vector< pair<vector<int>, char> > rankings(26);
		for (int i = 0; i < 26; ++i) 
			rankings[i] = make_pair(vector<int>(numTeams, 0), 'A' + i);
		
		for (auto &s : votes) {
			for (int i = 0; i < numTeams; ++i) {
				(rankings[ s.at(i) -'A' ].first)[i]++;
			}
		}      

		std::sort(rankings.begin(), rankings.end(), [](const pair<vector<int>,char> &p1, const pair<vector<int>,char> &p2){
			if (p1.first > p2.first) return true;
			if (p1.first < p2.first) return false;
			return p1.second < p2.second;
		});
		
		string result("");
		for (auto &rank : rankings) {
			result += rank.second;
			if (result.size() == numTeams) 
				break;
		}
		
		return result;
	}
};

int main(int argc, char *argv[]) {
	vector<string> votes{ "BCA","CAB","CBA","ABC","ACB","BAC" };
	Solution s;
	cout << s.rankTeams(votes);
}