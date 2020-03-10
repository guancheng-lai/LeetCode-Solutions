class Solution {
public:
	bool dfs(int currClass, unordered_map<int, vector<int> > &pre, unordered_map<int,int> &search) {
		search[currClass] = 1;
		for (auto c : pre[currClass]) {
			if (search[c] == 1) return false;
			if (search[c] == 2) continue;
			if (dfs(c, pre, search) == false) return false;
		}
		search[currClass] = 2;
		
		return true;
	}
	
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses <= 0 || prerequisites.size() == 0) return true;
		
		unordered_map<int, vector<int> > m;
		for (auto &v : prerequisites) m[ v[1] ].push_back( v[0] );
		
		unordered_map<int,int> search;
		//v=2 -> finished
		//v=1 -> visited
		//v=0 -> not visited
		
		for (auto &[k,v] : m) {
			if (search[k] == 2) continue;
			if (dfs(k, m, search) == false) return false;
		}
		
		return true;
	}
};