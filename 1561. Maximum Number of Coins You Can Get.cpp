class Solution {
public:
	int maxCoins(vector<int>& piles) {
		std::sort(piles.begin(), piles.end());
		int numRounds = piles.size() / 3;
		int idx = piles.size() - 2;
		int res = 0;
		for (int r = 0; r < numRounds; ++r) {
			res += piles[idx];
			idx -= 2;
		}
		return res;
	}
};