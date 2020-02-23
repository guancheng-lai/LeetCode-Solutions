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
using namespace std;

vector<int> closestDivisors(int num) {
		if (num == 1) return vector<int>{1,2};
		if (num == 2) return vector<int>{2,2};
		vector<int> result(2,0);
		int sqrt1 = sqrt(num + 1);
		if ((num+1) / sqrt1 == sqrt1 && (num+1) % sqrt1 == 0) return vector<int>{sqrt1, sqrt1};
		sqrt1++;
		if ((num+2) / sqrt1 == sqrt1 && (num+2) % sqrt1 == 0) return vector<int>{sqrt1, sqrt1};
		
		for (int i = sqrt1; i > 1; --i) {
			if ( (num+1) % i == 0) return vector<int>{i, (num+1)/i};
			if ( (num+2) % i == 0) return vector<int>{i, (num+2)/i};
		}
		
		return vector<int>{1,num+1};
	}

int main(int argc, char *argv[]) {
	vector<int> v = closestDivisors(123);
	for (auto i : v) cout << i << " " ;
}