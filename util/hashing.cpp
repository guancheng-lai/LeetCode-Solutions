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
	struct hash_pair { 
		template <class T1, class T2> 
		size_t operator()(const pair<T1, T2>& p) const
		{ 
			auto hash1 = hash<T1>{}(p.first); 
			auto hash2 = hash<T2>{}(p.second); 
			return hash1 ^ hash2; 
		} 
	}; 

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
	
	struct hash_unordered_map {
		template <class T1, class T2> 
		size_t operator() (const unordered_map<T1, T2>& m) const 
		{
			size_t hash_result;
			for (auto &[k,v] : m) {
				auto hash_k = hash<T1>{}(k);
				auto hash_v = hash<T1>{}(v);
				hash_result = hash_result ^ hash_k ^ hash_v;
			}
			return hash_result;
		}
	};
	
	struct hash_tree_map {
		template <class T1, class T2> 
		size_t operator() (const map<T1, T2>& m) const 
		{
			size_t hash_result;
			for (auto &[k,v] : m) {
				auto hash_k = hash<T1>{}(k);
				auto hash_v = hash<T1>{}(v);
				hash_result = hash_result ^ hash_k ^ hash_v;
			}
			return hash_result;
		}
	};
	
	struct hash_vector {
		template <class T> 
		size_t operator() (const vector<T>& v) const 
		{
			size_t hash_result;
			for (auto &i : v) {
				hash_result = hash_result ^ hash<T>{}(i);
			}
			return hash_result;
		}
	};
}

int main(int argc, char *argv[]) {
	unordered_map< pair<int,int>, int, hashing::hash_pair > memo;
	memo[{1,2}] = 3;
	cout << memo[{1,2}] ;
}