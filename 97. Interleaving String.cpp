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

namespace hashing {
    struct hash_tuple { 
        template <class T1, class T2, class T3> 
        size_t operator()(const tuple<T1, T2, T3>& tp) const
        { 
            auto hash1 = hash<T1>{}(get<0>(tp)); 
            auto hash2 = hash<T2>{}(get<1>(tp)); 
            auto hash3 = hash<T3>{}(get<2>(tp)); 
            return hash1 ^ hash2 ^ hash3;
        } 
    }; 
}

class Solution {
private:
	unordered_map< tuple<int,int,int>, bool, hashing::hash_tuple > m;
	bool helper(const string &s1, const string &s2, const string &s3, int i1, int i2, int i3) {
		if (i1 == s1.size() && i2 == s2.size()) return true;
		if (m.count( {i1,i2,i3} )) return m[{i1,i2,i3}];
		
		bool result1 = false, result2 = false;
		if (i1 != s1.size() && s3.at(i3) == s1.at(i1)) {
			result1 = helper(s1,s2,s3,i1+1,i2,i3+1);    
		} 
			
		if (i2 != s2.size() && s3.at(i3) == s2.at(i2)) { 
			result2 = helper(s1,s2,s3,i1,i2+1,i3+1);
		}  
		
		m[{i1,i2,i3}] = result1 || result2;;
		return result1 || result2;;
	}   
	
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size()) return false;
		if (s1.size() == 0) return s2 == s3;
		if (s2.size() == 0) return s1 == s3;
		return helper(s1,s2,s3,0,0,0);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	bool res = s.isInterleave(
		"cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc",
		"abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb",
		"abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb"
		);
	if (res) cout << "YES";
	else cout << "NO";
}