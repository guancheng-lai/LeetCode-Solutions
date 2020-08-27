class Solution {
public:
	string stoneGameIII(vector<int>& sv) {
		sv.push_back(0), sv.push_back(0), sv.push_back(0);
		size_t n = sv.size();
		vector<int> dp(n,0);
		for (int i = n-4; i >= 0; --i) {
			dp[i] = max({
				sv[i] - dp[i+1],
				sv[i] + sv[i+1] - dp[i+2],
				sv[i] + sv[i+1] + sv[i+2] - dp[i+3]
			});
		}
		if (dp[0] == 0) return "Tie";
		else if (dp[0] > 0) return "Alice";
		else return "Bob";
	}
};