class Solution {
public:
	int maxJumps(vector<int>& arr, int d) {
		const size_t len = arr.size();
		vector< pair<int,int> > v(len);
		for (int i = 0; i < len; ++i) {
			v[i] = {arr[i], i};
		}
		
		sort(v.begin(), v.end());
		vector<int> dp(len, 0);
		int result = 0;
		for (auto &[value, i] : v) {
			dp[i] = 1;
			for (int j = i + 1; j <= i + d && j < arr.size() && arr[j] < arr[i]; j++) {
				dp[i] = (dp[i] > (dp[j] + 1)) ? dp[i] : dp[j] + 1;
			}
			
			for (int j = i - 1; j >= i - d && j >= 0 && arr[j] < arr[i]; j--) {
				dp[i] = (dp[i] > (dp[j] + 1)) ? dp[i] : dp[j] + 1;
			}
			if (dp[i] > result) result = dp[i];
		}
		
		return result;
	}
};