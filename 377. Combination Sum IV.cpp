class Solution {
private:    
	unordered_map<int, int> m;
	
	int helper(vector<int> &nums, int currTarget) {
		if (currTarget < 0) return 0;
		
		if (m.count(currTarget) != 0) return m[currTarget];
		
		int result(0);
		for (int i = 0; i < nums.size(); ++i) {
			if (currTarget < nums[i]) continue;
			
			result += helper(nums, currTarget - nums[i]);
		}
		
		m[currTarget] = result;
		return result;
	}
	
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty() || target <= 0) return 0;
		// vector 
		// 4 ms     68.85% 
		// 9.1 MB   30.00%
		// vector<int> dp(target + 1, -1); dp[0] = 1;
		// return helper(nums, target, dp);
		
		// unordered_map
		// 4 ms     68.85% 
		// 10.1 MB   30.00%
		m[0] = 1;
		return helper(nums, target);
	}
};