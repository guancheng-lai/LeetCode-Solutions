class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		unordered_set<string> from,to;
		for (auto &vs : paths) {
			from.insert(vs[0]);
			to.insert(vs[1]);
		}
		
		for (auto &s : to) {
			if (from.find(s) == from.end()) return s;
		}
		
		return "";
	}
};