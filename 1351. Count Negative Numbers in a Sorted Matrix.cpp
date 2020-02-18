class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int count(0);
		
		for (auto &v : grid) {
			for (auto i : v) {
				if (i < 0) {
					count++;
				}
			}
		}
		
		return count;
	}
};