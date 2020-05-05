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

class Solution 
{
public:
	int firstUniqChar(string s) 
	{
		if (s.size() == 0) return -1;
		if (s.size() == 1) return 0;
		
		vector<int> cnt( 26,0 );
		vector<int> idx( 26,INT_MAX);
		
		for (int i = s.size()-1; i >= 0; i--) {
			cnt[ s[i]-'a' ]++;
			idx[ s[i]-'a' ] = i;
		}
		
		int minIdx = INT_MAX;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] == 1) {
				minIdx = min( minIdx,idx[i] );
			}
		}
			
		return minIdx == INT_MAX ? -1 : minIdx;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout <<	s.firstUniqChar("loveleetcode");
}