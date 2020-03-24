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
private:
    int smallest(int x, int y, int z){
        return x < y ? (x < z ? x : z) : (y < z ? y : z);
    }
    
	template <typename T>
	void printMatrix(const vector< vector<T> > &mat) {
		cout << "\n------MATRIX-------\n";
		for (auto &v : mat) {
			for (auto i : v) {
				cout << i << " ";
			}
			cout << endl;
		}
		cout << "\n-------------------\n";
	}
    
public:
	int minDistance(string word1, string word2) {
		size_t l1 = word1.size(), l2 = word2.size();
		if (l1 == 0) return l2;
		if (l2 == 0) return l1;
		
		vector< vector<int> > dp(l1+1, vector<int>(l2+1,0));
		for (int i = 0; i <= l1; ++i) dp[i][0] = i;
		for (int j = 0; j <= l2; ++j) dp[0][j] = j;
		
		for (int i = 1; i <= l1; ++i) {
			for (int j = 1; j <= l2; ++j) {
				if (word1.at(i-1) == word2.at(j-1)) {
					dp[i][j] = dp[i-1][j-1];
				}
				else{
					int ins = dp[i-1][j] + 1;
					int del = dp[i][j-1] + 1;
					int rep = dp[i-1][j-1] + 1;
					
					dp[i][j] = smallest( ins,del,rep );
				}
				
//				printMatrix(dp);
			}
		}
		
		return dp[l1][l2];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.minDistance("horse", "ros");
}