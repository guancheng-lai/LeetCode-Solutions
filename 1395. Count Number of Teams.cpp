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
	int numTeams(vector<int>& rating) {
		size_t len = rating.size();
		int count(0);
		for (int i = 0; i < len; ++i) {
			for (int j = i+1; j < len; ++j) {
				for (int k = j+1; k < len; ++k) {
					if (
						(rating[i] < rating[j] && rating[j] < rating[k])
						||
						(rating[i] > rating[j] && rating[j] > rating[k])
					) {
						count++;
					}
				}
			}
		}
		
		return count;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> rating{ 2,5,3,4,1 };
	cout << s.numTeams(rating);
}