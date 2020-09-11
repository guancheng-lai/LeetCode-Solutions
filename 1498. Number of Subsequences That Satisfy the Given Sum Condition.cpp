class Solution {
public:
	int MOD = 1e9 + 7;
	
	int numSubseq(vector<int>& nums, int target) {
		int N = nums.size();
		vector<int> powers(N, 1);
		for (int i = 1; i < N; ++i) {
			powers[i] = (powers[i-1] * 2) % MOD;
		}
		
		sort(nums.begin(), nums.end());
		int res = 0, left = 0, right = nums.size() - 1;
		while (left <= right) {
			if (nums[left] + nums[right] <= target) {
				res = (res + powers[right-left]) % MOD;
				left++;
			} else {
				right--;
			}
		}
		
		return res;
	}
};