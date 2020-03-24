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
using namespace std;

vector< vector<int> > result;

void dfs(int presum, int k, int n, vector<int> &inprogress) {
	for (auto i : inprogress) cout << i << " ";
	cout << endl;
	
	if ( presum == 0 ) { result.push_back(inprogress); return;}
	if (inprogress.size() == n) return;
	

	for (int num = 1; num <= k && presum - num >= 0; ++num) {
		inprogress.push_back(num);
		dfs(presum-num,k,n,inprogress);
		inprogress.pop_back();
	}
}

int main(int argc, char *argv[]) {
	int n = 3, k = 4, presum = 10; 
	vector<int> start;
	dfs(presum, k, n, start);
	cout << "{" << endl;
	for (auto &v : result) {
		if (v.size() < n) v.resize(n);
		
		cout << "{";
		for (int i = 0; i < n; ++i) {
			if (i != n-1) cout << v[i] << ",";
			else cout << v[i];
		}
		cout << "}," << endl;
	}
	cout << "}" << endl;
	

//	vector<int> start;
//	dfs(5, start);
//	cout << "{" << endl;
//	for (auto &v : result) {
//		if (v.size() < 4) v.resize(4);
//		bool ignore = false;
//		bool seenzero = false;
//		for (int i = 0; i < 4; ++i) {
//			if (v[i] == 0) {
//				if (seenzero) ignore = true;
//				else seenzero = true;
//			}
//		}
//		
//		if (ignore) continue;
//		
//		cout << "{";
//		for (int i = 0; i < 4; ++i) {
//			if (i != 3) cout << v[i] << ",";
//			else cout << v[i];
//		}
//		cout << "}," << ;
//	}
//	cout << "}" << endl;
//	
}