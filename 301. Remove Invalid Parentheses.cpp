class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		queue<string> q; q.push(s);
		unordered_set<string> visited; visited.insert(s);
		
		while (!q.empty()) {
			string curr = q.front(); q.pop();
			
			if (isValid(curr)) {
				if (!res.empty() && curr.size() < res.back().size()) {
					break;
				}
				
				res.push_back(curr);
				continue;
			}
			
			for (int i = 0; i < curr.size(); ++i) {
				if (curr[i] != '(' && curr[i] != ')') continue;
				
				string candidate = curr.substr(0, i) + curr.substr(i+1);

				if (visited.count(candidate) == 0) {
					visited.insert(candidate);
					q.push(candidate);
				}
			}
		}
		
		return res;
	}
};