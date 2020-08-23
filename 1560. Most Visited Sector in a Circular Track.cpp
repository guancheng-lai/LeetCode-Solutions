class Solution {
public:
	vector<int> mostVisited(int n, vector<int>& rounds) {
		vector<int> res(n+1, 0);
		for (int i = 0; i < rounds.size() - 1; ++i) {
			if (rounds[i+1] == rounds[i]) {
				res[ rounds[i] ]++;
			} else if (rounds[i+1] < rounds[i]) {
				for (int s = rounds[i]; s <= n; ++s) res[s]++;
				for (int s = 1; s < rounds[i+1]; ++s) res[s]++;
			} else {
				for (int s = rounds[i]; s < rounds[i+1]; ++s) res[s]++;
			}
		}
		res[rounds.back()]++;
		
		int maxVisited = -1;
		vector<int> maxSectors;
		for (int i = 1; i < res.size(); ++i) {
			if (res[i] == maxVisited) {
				maxSectors.push_back(i);
			} else if (res[i] > maxVisited) {
				maxSectors.clear();
				maxSectors.push_back(i);
				maxVisited = res[i];
			}
		}
		
		return maxSectors;
	}
};