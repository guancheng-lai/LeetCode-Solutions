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
	int checkRecord(int n) {
		constexpr int M = 1e9 + 7;
		if (n <= 0) return 0;
		
		vector<int> p(n+1),a(n+1),l(n+1);
		p[1] = 1, p[2] = 3, p[3] = 8;
		a[1] = 1, a[2] = 2, a[3] = 4;
		l[1] = 1, l[2] = 3, l[3] = 7;
		
		for (int i = 4; i <= n; ++i) {
			p[i] = ( (p[i-1] + a[i-1])%M + l[i-1] )%M;
			a[i] = ( (a[i-1] + a[i-2])%M + a[i-3] )%M;
			l[i] = ( (p[i-1] + a[i-1])%M + (p[i-2] + a[i-2])%M ) %M;
			
			cout << "i = " << setw(10) << i 
					<< " ---> p=" << setw(5) << p[i] 
					<< ", a=" << setw(5) << a[i] 
					<< ", l=" << setw(5) << l[i] << endl;
		}
		
		return ((p[n] + a[n])%M + l[n])%M;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.checkRecord(10);	
}