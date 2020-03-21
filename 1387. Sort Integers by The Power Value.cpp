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
	int power(int i, int p) {
		if (i == 1) return p;
		if (i % 2 == 0) return (power(i/2, p+1));
		else return power(i*3 + 1, p+1);
	}
	
	int getKth(int lo, int hi, int k) {
		vector< pair<int,int> > result;
		for (int i = lo; i <= hi; ++i) {
			result.push_back( {power(i,0),i} );
		}
		
		nth_element(result.begin(), result.begin() + k - 1, result.end());
		return result[k-1].second;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.getKth(10, 20, 5);	
}