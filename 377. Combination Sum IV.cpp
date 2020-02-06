class Solution {
private:    
	int helper(vector<int> &nums, int currTarget, vector<int> & dp) {
		if (currTarget < 0) return 0;
		
		if (dp[currTarget] != -1) return dp[currTarget];
		
		int result(0);
		for (int i = 0; i < nums.size(); ++i) {
			if (currTarget < nums[i]) continue;
			
			result += helper(nums, currTarget - nums[i], dp);
		}
		
		dp[currTarget] = result;
		return result;
	}
	
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty() || target <= 0) return 0;
		vector<int> dp(target + 1, -1); dp[0] = 1;
		return helper(nums, target, dp);
	}
};